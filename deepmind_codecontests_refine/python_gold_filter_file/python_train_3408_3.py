import sys
import math
from collections import defaultdict
n=int(sys.stdin.readline())
arr=list(map(int,sys.stdin.readline().split()))
vis=defaultdict(int)
ans,num=1,arr[0]
for i in range(n):
    vis[arr[i]]=1
x=max(arr)
dif=-1
for i in range(n):
    #cnt=1
    for k in range(31):
        #cnt=1
        if arr[i]+(1<<k) in vis and arr[i]+(1<<(k+1)) in vis:
            cnt=3
            if cnt>ans:
                ans=cnt
                num=arr[i]
                dif=(1<<k)
        if arr[i]+(1<<k) in vis:
            cnt=2
            if cnt>ans:
                ans=cnt
                num=arr[i]
                dif=(1<<k)
if ans==3:
    res=[num,num+dif,num+2*dif]
if ans==2:
    res=[num,num+dif]
if ans==1:
    res=[num]
#print(ans)
'''for k in range(1,31):
    if vis[num+(1<<k)]==1:
        res.append(num+(1<<k))
    else:
        break
rem=num
print(ans,'daea',num,'numm')
if ans<=2:
    num=-1
    for i in range(n):
        cnt=1
        if vis[arr[i]+1]==1:
            cnt+=1
        if cnt>ans:
            ans=cnt
            num=arr[i]
        if vis[arr[i]+2]==1:
            cnt+=1
        if cnt>ans:
            num=arr[i]
            ans=cnt
    #print(ans,'in if')
    if num!=-1 and ans==3:
        print(3)
        print(num,num+1,num+2)
        sys.exit()
    if num!=-1 and ans==2:
        print(2)
        if vis[num+1]==1:
            print(num,num+1)
            sys.exit()
        if vis[num+2]==1:
            print(num,num+2)
            sys.exit()'''
print(ans)
print(*res)
