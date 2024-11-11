n = int(input())
for i in range(n):
    a, b, c = sorted(map(int, input().strip().split()))
    print('YES' if a**2 + b**2 == c**2 else 'NO')