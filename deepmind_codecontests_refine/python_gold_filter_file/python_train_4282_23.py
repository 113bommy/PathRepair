n, s = map(int, input().split())
v = [int(i) for i in input().split()]
v.sort()
sum_ = 0
for i in range(n):
    sum_ += v[i] - v[0]
if sum_ >= s:
    print(v[0])
else:
    print((n * v[0] - s + sum_) // n if (n * v[0] - s + sum_) >= 0 else -1)
