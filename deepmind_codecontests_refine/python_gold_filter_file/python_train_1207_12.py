n,k = map(int,input().split())
a = list(map(int,input().split()))

a = sorted(a)

k*=2
c = 0

for i in range(n):
    while a[i]>k:
        c+=1
        k *= 2
    k = 2*max(k//2,a[i])
        
print(c)