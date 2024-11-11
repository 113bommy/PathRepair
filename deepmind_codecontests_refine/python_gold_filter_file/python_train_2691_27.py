from math import ceil
N, A, B = map(int, input().split())
H = [int(input()) for i in range(N)]

A = A - B
ng, ok = 0, 10 ** 9 + 1
while abs(ok - ng) > 1:
    X = (ng + ok) // 2
    H_damaged = [h - B * X for h in H]
    need = sum([max(ceil(h / A), 0) for h in H_damaged])

    if need <= X:
        ok = X
    else:
        ng = X

print(ok)
