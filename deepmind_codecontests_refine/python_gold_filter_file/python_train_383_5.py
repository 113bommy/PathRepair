n = int(input())
a = sorted(map(int, input().split()))
o, e = 0, 0
for i in range(n//2):
  o += abs(a[i] - (i * 2 + 2))
  e += abs(a[i] - (i * 2 + 1))
print(min(o, e))