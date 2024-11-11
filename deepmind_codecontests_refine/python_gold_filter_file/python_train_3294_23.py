import math

t = int(input())

for i in range(t):
    n, k = map(int, input().split())
    positions = list(map(int, input().split()))
    ans = max(positions[0], n - positions[-1] + 1)
    for j in range(1, k):
        ans = max(ans, math.ceil((positions[j] - positions[j - 1] + 1) / 2))
    print(ans)
