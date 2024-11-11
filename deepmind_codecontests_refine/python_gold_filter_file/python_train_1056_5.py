n = int(input())
s = a = 0
for c in input():
    s += 1 if c == '+' else -1
    a = min(a, s)
print(s-a)