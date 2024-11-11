for _ in range(int(input())):
    cols = int(input())
    s = not not (int(input(), 2) & int(input(), 2))
    print("NO" * s + "YES" * (not s))