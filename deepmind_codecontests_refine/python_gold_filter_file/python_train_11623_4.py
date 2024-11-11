v1, v2, v3, vm = map(int, input().split())
f1, f2 = max(v1, 2 * vm + 1), 2 * v1
m1, m2 = max(v2, 2 * vm + 1), 2 * v2
s1, s2 = max(v3, vm), min(2 * v3, 2 * vm)
if f1 > f2 or m1 > m2 or s1 > s2:
    print(-1)
else:
    print(f2, m2, s2, sep='\n')