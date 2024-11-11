from collections import Counter

n, k = map(int, input().split())
s = list(input())

s2 = Counter(s)

if len(s2.keys()) != k:
    print(0)
else:
    s3 = s2.values()
    s3 = sorted(s3)
    print(int(s3[0]) * k)
