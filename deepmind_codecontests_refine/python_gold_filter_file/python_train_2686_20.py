p = int(input())
A = list(map(int, input().split()))
comb = [0]*p
comb[0] = 1
for i in range(1, p):
    comb[i] = comb[i-1] * (p-i) * pow(i, p-2, p) % p

B = [0]*p
for i in range(p):
    if A[i] == 0:
        continue
    B[0] += 1
    Pow = 1
    for j in range(p):
        B[p - 1 - j] = (B[p - 1 - j] - comb[j] * Pow) % p
        Pow = Pow * (-i) % p
print(*[b % p for b in B])