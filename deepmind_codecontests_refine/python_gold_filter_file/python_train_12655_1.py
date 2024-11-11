n,k = list(map(int, input().split(" ")))
a = list(map(int, input().split(" ")))
sum=0
for i in range(1,n):
    sum+=max(k-a[i-1]-a[i],0)
    a[i]+=max(k-a[i-1]-a[i],0)
print(sum)
print(*a)