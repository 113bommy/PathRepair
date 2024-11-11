n = int(input())
lo = 10 ** 10
diff = -10 ** 9
for _ in range(n):
    r = int(input())
    diff = max(diff, r - lo)
    lo = min(lo, r)
print(diff)
