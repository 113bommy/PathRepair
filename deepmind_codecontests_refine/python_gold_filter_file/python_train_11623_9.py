f, m, s, p = map(int, input().split())

c1 = f*2
c2 = m*2

if p >= m:
    print(-1)
    exit()

if max(p, s)/2 <= min(p, s) <= max(p, s):
    c3 = min(p, s)*2
else:
    print(-1)
    exit()

print(c1)
print(c2)
print(c3)

