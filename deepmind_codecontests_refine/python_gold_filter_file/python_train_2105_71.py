n = int(input())
c = input()
l = 0
r = 0
for i in range(len(c)):
    if c[i] == 'L':
        l += 1
    elif c[i] == 'R':
        r += 1
print(l + r + 1)