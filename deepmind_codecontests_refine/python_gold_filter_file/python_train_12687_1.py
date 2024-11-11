import sys

a, b = [], []
for line in sys.stdin:
    x, y = map(int, line.strip().split(","))
    a, b = a+[x*y], b+[y]
print(sum(a))
print(int(sum(b)/len(b)+0.5))