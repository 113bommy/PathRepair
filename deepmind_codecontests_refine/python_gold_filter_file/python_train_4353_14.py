n = int(input())
l = []
for i in range(n):
    a, b = input().split()
    l.append((a, -int(b), i + 1))
l.sort()
for e in l:
    print(e[2])