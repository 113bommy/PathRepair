def mi():
        return map(int, input().split())
n,k = mi()
a = list(range(2*n+1))
for i in range(1, k+1):
        a[2*i], a[2*i-1] = a[2*i-1], a[2*i]
print (*a[1:])
