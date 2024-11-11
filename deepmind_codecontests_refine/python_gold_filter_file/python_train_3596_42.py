n,x = map(int, input().split())
a = [input() for i in range(n)]
t = 0
k = 0
for j in range(n):
    if a[j][0] == '-':
        if x >= int(a[j][1:]):
            x -= int(a[j][1:])
        else:
            t += 1
    elif a[j][0] == '+':
        x += int(a[j][1:])
print(x,t)