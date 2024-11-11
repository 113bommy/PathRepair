def solve(n, a):
    if n == 1:
        return a[0]
    elif n == 2:
        return max(a)
    even_sum = sum(a[i] for i in range(0, n, 2))
    la, lb = [], []
    for i in range(n - 1):
        if i % 2 == 0:
            la.append(-a[i] + a[i + 1])
        else:
            lb.append(a[i] - a[i + 1])

    ta, tb = [la[0]], [lb[0]]
    for e in la[1:]:
        ta.append(max(e, ta[-1] + e))
    for e in lb[1:]:
        tb.append(max(e, tb[-1] + e))
    return even_sum + max(max(ta), max(tb), 0)


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    print(solve(n, a))
