n=int(input())
a=list(map(int,input().split()))
sum=0
for i in range(n):
    sum+=a[i]
print(n if sum%n==0 else n-1)
