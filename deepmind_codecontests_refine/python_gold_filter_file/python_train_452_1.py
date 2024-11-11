from collections import defaultdict
p, n = defaultdict(int), int(input())
for i in map(int, input().split()):
    p[bin(i).count('1')] += 1
print(sum(x * (x - 1) for x in p.values()) // 2)