n, m, a = map(int, input().split())
r1 = m/a
r2 = n/a
if r1 != int(r1):
    r1 = int (r1) + 1
if r2 != int(r2):
    r2 = int (r2) + 1
print(int(r1 * r2))
