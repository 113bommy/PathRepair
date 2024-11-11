from itertools import product
N, K = list(map(int, input().split()))
D = set(range(10)) - set(list(map(int, input().split())))
ans = float("inf")
for i in range(2):
    for s in product(D, repeat=len(str(N))+i):
        n = int("".join(map(str, s)))
        if n >= N and ans - N > n - N:
            ans = n
print(ans)
