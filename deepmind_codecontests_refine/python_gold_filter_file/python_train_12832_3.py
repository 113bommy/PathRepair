#Consistency is the key.
#code by: amrit00
from sys import stdin,stdout
import math
input=stdin.readline
def print(*args,end='\n'):
    s=[]
    for i in args:
        s.append(str(i)+' ')
    s=''.join(s)
    stdout.write(s+end)
    

def solve():
    n=int(input())
    l=list(map(int,input().split()))
    maxx=0
    d=[]
    for i in range(n):
        for j in range(n):
            if i==j:
                continue
            else:
                s=l[i]+l[j]
                d.append(s)
                    

    d=list(set(d))

    for s in d:
        used=[False]*n
        ans=0
        for j in range(n):
            for k in range(n):
                if j==k:
                    continue
                if l[j]+l[k]==s and not used[j] and not used[k]:
                    ans+=1
                    used[j]=True
                    used[k]=True
        if ans>maxx:
            maxx=ans
        
    print(maxx)
                        
tt=1
tt=int(input())
for __ in range(tt):
    solve()
