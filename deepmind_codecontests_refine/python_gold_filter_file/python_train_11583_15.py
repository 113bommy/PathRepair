'''Author- Akshit Monga'''
import math
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    s=input()
    delta=0
    bool=0
    ans=0
    var=0
    for i in s:
        if i=='0':
            delta+=1
            var=0
        if i=='1':
            if bool==0:
                ans+=delta//(k+1)
                bool=1
            else:
                ans+=(delta-k)//(k+1)
            var=1
            delta=0
        # print(ans)
    if var==0:
        ans += (delta) // (k + 1)
    if bool==0:
        ans=(delta+k)//(k+1)
    print(ans)