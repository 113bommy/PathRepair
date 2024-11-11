n = int(input())
min_r, max_d = int(input()), - 10**9
for _ in range(n - 1):
    r = int(input())
    max_d = max(max_d, r - min_r)
    min_r = min(min_r, r)
print(max_d)

