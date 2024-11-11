X, Y, Z, K = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

C = sorted(C, reverse=True)
AB = sorted([a + b for a in A for b in B], reverse=True)

ABC_k = sorted([ab + c for ab in AB[:K] for c in C], reverse=True)

for ans in ABC_k[:K]:
    print(ans)