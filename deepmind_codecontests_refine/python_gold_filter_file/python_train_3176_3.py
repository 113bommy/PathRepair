n, t = input().split()
n = int(n)
t = int(t)
if t == 10:
    if n == 1:
        print(-1)
    else:
        for i in range(0, n-1):
            print(1, end="")
        print(0)
else:
    for i in range(0, n):
        print(t, end="")