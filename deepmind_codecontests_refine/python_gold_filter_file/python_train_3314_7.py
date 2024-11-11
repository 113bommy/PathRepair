n, k = map(int, input().split())
a = list(map(int, input().split()))
d = [0] * n
for i in a: d[i-1] += 1
d.sort(reverse=True)
print(n-sum(d[0:k]))
