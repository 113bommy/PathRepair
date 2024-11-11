# 552B
n = int(input())
d = 0
while n/10**d >= 1:
    d += 1
cif = 0
for j in range(1,d):
    cif += j*9*10**(j-1)
cif += d*(n-10**(d-1)+1)
print(cif)