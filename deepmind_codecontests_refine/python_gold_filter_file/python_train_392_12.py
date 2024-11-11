n = int(input())

a = [int(input()) for _ in range(n)]

b = sorted(a)

for x in a:
    if x == b[-1]:
        print(b[-2])
    else:
        print(b[-1])