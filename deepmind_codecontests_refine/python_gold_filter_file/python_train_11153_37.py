from itertools import permutations

n = int(input())
s = input()
ans = n
sans='kek'
z1 = s[0::3]
z2 = s[1::3]
z3 = s[2::3]

for i in permutations(["R","G","B"]):
    kol = 0
    kol += len(list(filter(lambda c: c != i[0], z1)))
    kol += len(list(filter(lambda c: c != i[1], z2)))
    kol += len(list(filter(lambda c: c != i[2], z3)))
    if kol<ans:
        ans = kol
        sans = ''.join(i)*len(z3)
        sans = sans + i[0] * (len(z1) - len(z3))
        sans = sans + i[1] * (len(z2) - len(z3))

print(ans)
print(sans)


