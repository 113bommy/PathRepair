n,m=map(int,input().split())
if m>=n:
    from sys import exit
    print(n);exit()
i,j=m,n
result=m
item=m*(m+1)//2
while i+1<j:
    mid=(i+j)//2
    if mid*(mid+1)//2-item>=n+m*(mid-m-1):j=mid
    else:i=mid
if i*(i+1)//2-item>=n+m*(i-m-1):print(i)
else:print(j)