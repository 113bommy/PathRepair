n = int(input())
b = [0] + list(map(int, input().split()))
p = [0 for i in range(n + 1)]
for i in range(1, n + 1):
    p[i] = b[i] - i
sum_ = [0 for i in range(10**6)]
max_ = 0
for i in range(1, n + 1):
    sum_[p[i]] += b[i]
    if sum_[p[i]] > max_:
        max_ = sum_[p[i]]
print(max_)
