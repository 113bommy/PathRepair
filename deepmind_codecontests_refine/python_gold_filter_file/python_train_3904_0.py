n, m, k = [int(x) for x in input().split()]
canwin = False
for i in range(k):
  x, y = [int(x) for x in input().split()]
  canwin |= x < 6 or n - x < 5
  canwin |= y < 6 or m - y < 5
print("YES" if canwin else "NO")
