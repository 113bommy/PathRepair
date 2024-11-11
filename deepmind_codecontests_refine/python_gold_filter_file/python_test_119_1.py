t = int(input())
for _ in range(t):
    n = int(input())
    a = [int(a) for a in input().split()]
    if sum(a) % n == 0:
        print(0)
    else:
        print(1)
