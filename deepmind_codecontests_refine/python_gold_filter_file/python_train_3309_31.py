s, t = input().split()
a, b = map(int, input().split())
c = input()
if c == s: a -= 1
else: b -= 1
print(a, b)