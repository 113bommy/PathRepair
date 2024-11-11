import sys
import fractions

lines = []
for line in sys.stdin:
    num = line.split(" ")
    a, b = int(num[0]), int(num[1])
    gcd = fractions.gcd(a, b)
    print("{0} {1:.0f}".format(gcd, (a*b)/gcd))