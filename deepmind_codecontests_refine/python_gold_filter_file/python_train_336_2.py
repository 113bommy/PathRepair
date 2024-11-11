n = int(input())
M = int(1e9 + 7)

fac = [1]

for i in range(1, int(1e6 + 1)):
    fac.append((fac[-1] * i) % M)
    
print((fac[n] - pow(2, n - 1, M)) % M)