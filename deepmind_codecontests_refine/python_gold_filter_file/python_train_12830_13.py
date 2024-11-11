def solve(N, A):
    total = -1
    A.sort()
    for i in range(N - 1, -1, -1):
        if A[i] <= i + 1:
            total = i
            break
    if total == -1:
        print(1)
    else:
        print(total + 2)


t = int(input())
while t != 0:
    n = int(input())
    a = list(map(int, input().split(' ')))
    solve(n, a)
    t -= 1

