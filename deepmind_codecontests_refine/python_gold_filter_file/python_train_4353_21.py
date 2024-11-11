n = int(input())
l = []
for i in range(n):
    s, p = input().split()
    l.append((s, -int(p), i + 1))

l.sort()
for i in l:
    print(i[2])