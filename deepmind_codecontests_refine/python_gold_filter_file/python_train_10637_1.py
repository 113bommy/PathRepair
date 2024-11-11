n=int(input())
a=list(map(int,input().split()))
p=0
ans=0
while a[0]:
    for i in range(n):
        x=a[i]%10
        ans=(ans+(10*x+x)*n*(10**(p)))%998244353 
        a[i]=a[i]//10
    p=p+2
print(ans%998244353)