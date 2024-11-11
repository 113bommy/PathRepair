from sys import stdin, setrecursionlimit as srl
from threading import stack_size, Thread
 
srl(int(1e9)+7)
stack_size(int(1e8))

ans = 0
before = []
after = []

def solve():
    
    global ans, after, before
    def tree(d,i):
        if len(d[i])==0:
            return
        for j in d[i]:
            d[j].remove(i)
        for j in d[i]:
            i=j
            tree(d,i)
    
    def traverse(d,i,a,b):
        global ans, after, before
        for j in d[i]:
            traverse(d,j,a,b)
        ans+=a[i]
        if a[i]>0 and b[i]!=-1:
            a[b[i]-1]+=a[i]
            before.append(i+1)
        elif a[i]>0:
            before.append(i+1)
        else:
            after.append(i+1)
        return
 
    n = int ( input() )
    a = list ( map ( int, input().split() ) )
    b = list ( map ( int, input().split() ) )
    
    terminators = []
    for i in range(n):
        if b[i]==-1:
            terminators.append(i)
    
    d={}
    for i in range(n):
        d[i]=[]
    
    for i in range(n):
        if b[i]!=-1:
            d[i].append(b[i]-1)
            d[b[i]-1].append(i)
    
    for i in terminators:
        tree(d,i)
    for i in terminators:
        traverse(d,i,a,b)

        
    print(ans)
    after.reverse()
    before+=after 
    print(*before)

Thread(target=solve).start()