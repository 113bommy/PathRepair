#!/usr/bin/env python3

import sys
input=sys.stdin.readline

t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    if k==1:
        if len(set(arr))!=1:
            print(-1)
        else:
            print(1)
        continue
    else:
        #answer is always exists
        ans=1
        pos=0
        cnt=0
        prev=-1
        while pos<n:
            if prev<arr[pos]:
                cnt+=1
                if cnt>k:
                    ans+=1
                    cnt=1
                    continue
                prev=arr[pos]
            pos+=1
        print(ans)