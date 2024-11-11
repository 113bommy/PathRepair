from collections import defaultdict

n, k = map(int, input().split())
count, prev, total = defaultdict(int), '', 1

for ch in input() + ' ':
    if ch == prev:
        total += 1
    else:
        count[prev], total = count[prev] + total // k, 1
    prev = ch

print(max(count.values()))