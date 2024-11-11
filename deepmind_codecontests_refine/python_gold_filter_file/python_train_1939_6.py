n=2*int(input())
arr=sorted(map(int,input().split()))
x=arr[n-1]
for i in range(n):
    for j in range(i):
        u=arr[:j]+arr[j+1:i]+arr[i+1:]
        a=sum(u[h+1]-u[h] for h in range(0,n-3,2))
        x=min(x,a)
print(x)