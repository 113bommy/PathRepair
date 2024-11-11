n, A, B, C, T = map(int, input().split())
t = list(map(int, input().split()))
d = C - B
if d < 0:
    print(n * A)
else:
    num = 0
    for i in range(n):
        num += (C - B) * (T - t[i])
        num += A

    print(num)