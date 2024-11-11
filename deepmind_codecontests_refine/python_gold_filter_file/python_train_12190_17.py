from decimal import *

n, m = [int(_) for _ in  input().split()]
n2 = n//2
getcontext().prec = 6000
avg = Decimal(0.0)

negative = Decimal(0.0)
positive = Decimal(0.0)
for c in range(m):
				x, d = [int(_) for _ in input().split()]
				avg += Decimal(x) * Decimal(n)
				if d < 0:
								negative += d
				else:
								positive += d
# Fix the negative part
avg += Decimal(n2*(n2+1)) * negative
if n % 2 == 0:
				avg -= Decimal(n2) * negative
# Fix the positive part
avg += Decimal(n *(n-1) / 2) * positive

print ("%.20lf" % (avg / Decimal(n)))
