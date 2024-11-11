from fractions import gcd

A, B, C = map(int, input().split())

print('YES' if C % gcd(A, B) == 0 else 'NO')