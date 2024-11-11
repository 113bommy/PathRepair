import fractions
a, b, c = map(int, input().split())
print("YES" if c%(fractions.gcd(a,b)) == 0 else "NO")