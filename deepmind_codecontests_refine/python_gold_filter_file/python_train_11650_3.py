import sys

while True:
    n = int(input())
    if n == 0:
        break;
    x = {}
    for i in range(n):
        k,v = sys.stdin.readline().rstrip().split()
        x[k] = v
    y = []
    for i in range(int(input())):
        a = sys.stdin.readline().rstrip()
        if a in x:
            y.append(x[a])
        else:
            y.append(a)
    print(''.join(y))