import sys
input=sys.stdin.readline
import collections as cc
I=lambda:list(map(int,input().split()))
for tc in range(int(input())):
    n,=I()
    l=I()
    f=cc.defaultdict(int)
    for i in range(n):
        f[l[i]]=i
    ans='Yes'
    for i in range(1,n):
        if f[i]>f[i+1] or f[i]+1==f[i+1]:
            ans='Yes'
        else:
            ans='No'
            break
    print(ans)
                
        