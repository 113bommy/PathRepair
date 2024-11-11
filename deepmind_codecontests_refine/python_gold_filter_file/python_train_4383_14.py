from collections import Counter
n = int(input())
arr = list(map(int, input().split()))
c = Counter(arr)

Max = 0
for key, val in c.items():
    if val > Max:
        Max = val

print(n-Max)
