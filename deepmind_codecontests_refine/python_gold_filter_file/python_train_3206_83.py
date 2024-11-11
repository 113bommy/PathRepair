a, b, k = map(int, input().split())
c = min(a,k)
a -= c
k -= c
b -= min(b, k)
print(a, b)