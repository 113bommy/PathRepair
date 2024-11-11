q = int(input())
for i in range(q):
    cf = [int(i) for i in input().split()]
    a, b, n, S = cf[0], cf[1], cf[2], cf[3]
    if S % n <= b and a * n + b >= S:
        print("yes")
    else:
        print("no")