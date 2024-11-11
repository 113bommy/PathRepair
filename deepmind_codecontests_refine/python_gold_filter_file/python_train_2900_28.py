I, O, T, J, L, S, Z = map(int, input().split())
k0 = 0
k0 += (I//2)*2
k0 += (J//2)*2
k0 += (L//2)*2

k1 = 0
if I >= 1 and J >= 1 and L >= 1:
    k1 = 0
    k1 += 3
    I -= 1
    J -= 1
    L -= 1
    k1 += (I//2)*2
    k1 += (J//2)*2
    k1 += (L//2)*2

k = max(k0, k1)
k += O
print(k)