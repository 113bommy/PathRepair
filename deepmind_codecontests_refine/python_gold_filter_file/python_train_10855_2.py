t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    sm = sum(a)
    if sm % n:
        print(-1)
        continue
    avg = sm // n

    ans = []

    print(3*n-3)
    for i, ai in enumerate(a[1:], 2):
        d = (i - ai % i) % i
        print(1, i, d)
        print(i, 1, (ai + d)//i)
    for i, ai in enumerate(a[1:], 2):
        print(1, i, avg)

'''
3
4
2 16 4 18
6
1 2 3 4 5 6
5
11 19 1 1 3

'''