n, t = map(int, input().split())
if t < 10:
    print("".join(str(t) for _ in range(n)))
elif n > 1:
    print("1" + "".join("0" for _ in range(n - 1)))
else:
    print(-1)
