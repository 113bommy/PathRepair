n = int(input())
a = [int(input()) for _ in range(n)]
b = sorted(a)
for ai in a:
    if ai == b[-1]:
        print(b[-2])
    else:
        print(b[-1])
