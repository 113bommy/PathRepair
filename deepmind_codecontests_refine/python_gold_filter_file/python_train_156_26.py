n,k = map(int,input().split())
a = list(map(int,input().split()))
k -= 1
for i in range(1,n+1):
    if k-i>=0:
        k = k-i
    else:
        break
print(a[k])
