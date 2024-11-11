__author__ = 'asmn'
n=int(input())
a=list(map(int,input().split()))
ans,nl=0,0
for i in range(2,n):
    if a[i]==a[i-1]+a[i-2]:
        nl+=1
        ans=max(ans,nl)
    else:
        nl=0

print(ans+min(2,n))