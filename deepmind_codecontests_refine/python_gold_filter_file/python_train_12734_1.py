'''7 3
abacaba
1 3
2 5
1 7
'''
import string
def solve():
    n,q=map(int,input().split())
    s=input()
    d={}
    ans=0
    l=[0]*(n+1)
    for i in range(1,n+1):
        l[i]=l[i-1]+(ord(s[i-1])-96)
    #print(l)
    for _ in range(q):
        r,e=map(int,input().split())
        print(l[e]-l[r-1])
        #print(l[r-1])
















solve()
