from math import ceil
N, A, B = map(int, input().split())
H = [int(input()) for i in range(N)]
A -= B  # Aを追加ダメージ扱いにする


ok, ng = 10 ** 9, 0
while abs(ok - ng) > 1:
    X = (ok + ng) // 2
    H_damaged = [h - (B * X) for h in H if h - (B * X) > 0]
    Need = sum([ceil(h / A) for h in H_damaged])

    if X >= Need:
        ok = X
    else:
        ng = X

print(ok)
