n, k = map(int, input().split())
p = list(map(int, input().split()))
a = sum(p[0:k])
l = [a]
for i in range(n-k):
    a = a-p[i]+p[i+k]
    l.append(a)
print((max(l)+k)/2)