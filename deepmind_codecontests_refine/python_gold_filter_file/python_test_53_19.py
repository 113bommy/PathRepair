from sys import stdin 
from bisect import bisect
for _ in range(int(stdin.readline())):
    inp=list(input().split())
    s=input()
    n=int(inp[0])
    c=inp[1] 
    ans=0
    for i in range(n):
        if s[i]!=c:
            ans=1 
            break 
    if ans==0:
        print(ans) 
    else:
        ans=None
        for i in range(n):
            if (i+1)*2>n and s[i]==c:
                ans=i+1 
                break 
        if ans!=None:
            print(1)
            print(ans)
        else:
            print(2)
            print(n-1,n)