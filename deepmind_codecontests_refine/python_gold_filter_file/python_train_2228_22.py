n, m = map(int, input().split())

p = sorted(map(int, input().split()))


diff = p[n - 1] - p[0]


for i in range(n, len(p)):
    newdiff = p[i] - p[i - n + 1]
    diff = min(diff, newdiff)
print(diff)
