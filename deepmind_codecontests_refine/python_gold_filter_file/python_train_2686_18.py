p = int(input())
a = [int(item) for item in input().split()]

fac = [1] + [0] * (p - 1)
facinv = [1] + [0] * (p - 1)
for i in range(1, p):
    fac[i] = fac[i-1] * i % p
    facinv[i] = facinv[i-1] * pow(i, p-2, p) % p

# print(fac)
# print(facinv)
comb = [0] * p
for i in range(p):
    comb[i] = fac[p-1] * facinv[i] * facinv[p-1-i] % p

# print(comb)
ans = [0] * p
ppowp = [[0] * (p + 1) for _ in range(p + 1)]
for i in range(p+1):
    val = 1
    for j in range(p+1):
        ppowp[i][j] = val
        val *= i
        val %= p

for i, item in enumerate(a):
    if item == 1:
        ans[0] += 1
        # Calc (i - x)**(p - 1) 
        for j in range(p):
            # ans[j] -= pow(i, p-1-j, p) * pow(-1, j, p) * comb[j] % p
            if j % 2 == 1:
                ans[j] -= ppowp[i][p-1-j] * -1 * comb[j] % p
            else:
                ans[j] -= ppowp[i][p-1-j] * comb[j] % p
            ans[j] %= p
print(" ".join([str(item) for item in ans]))