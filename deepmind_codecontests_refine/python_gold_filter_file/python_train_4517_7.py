n,k = map(int, input().split())
a = [n-i for i in range(n)]
x = a[:k+1]
y = a[k+1:]

y = y[::-1] + x
print(" ".join([str(i) for i in y]))