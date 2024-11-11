from math import *
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    s=['a']*n
    for i in range(n-2,-1,-1):
        c=n-i-1
        if c>=k:
            s[i]='b'
            s[n-k]='b'
            break
        else:
            k=k-c
    e=''
    print(e.join(s))
    
    