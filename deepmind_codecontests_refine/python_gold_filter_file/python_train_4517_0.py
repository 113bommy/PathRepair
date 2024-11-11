n,k = map(int,input().split())
a = [i for i in range(1,n+1)]
b = a[n-k:]
c = a[:n-k]
a = b[::-1]+c
print(*a)