n = int(input())
cum = 0
d = dict()
for _ in range(n):
    a, b = input().split()
    b = int(b)
    cum += b
    d[a] = cum
c = input()
print(cum - d[c])