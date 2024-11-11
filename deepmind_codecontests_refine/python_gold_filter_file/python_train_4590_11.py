s = []
while True:
    n, x = map(int, input().strip().split())
    if n == x == 0:
        break
    c = 0
    for i in range(1,x//3):
        c += max(0, max(0,(x -3*i -1)//2) - max(0,(x -2*i -1 -n)))
    s.append(str(c))
print('\n'.join(s))