n, m = map(int, input().split())

s1 = set()
for _ in range(n):
    s1.add(input())

s2 = set()
for _ in range(m):
    s2.add(input())

nm = len(s1 & s2)

if n + (0 if nm%2==0 else 1) > m:
    print('YES')
else:
    print('NO')