import fractions
 
A,B,C = map(int, input().split())
 
ret = C % fractions.gcd(A,B) == 0
print('YES' if ret else 'NO')