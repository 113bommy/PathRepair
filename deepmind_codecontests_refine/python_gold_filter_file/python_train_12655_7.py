n,k=map(int,input().split())
a=list(map(int,input().split()))
answer=0
for i in range(1,n):
    if a[i]+a[i-1]<k:
        answer+=k-a[i]-a[i-1]
        a[i]=k-a[i-1]
print(answer)
for i in range(n):
    print(a[i],end=' ')


        