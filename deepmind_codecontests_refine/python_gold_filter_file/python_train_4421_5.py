n, a = int(input()), list(map(int, input().split()))
c = f = -1
for i in a:
    c = c + 1 if i == 1 and i == f else c + 2 if i == 1 else c + 0
    f = i
print(0 if c == -1 else c)
