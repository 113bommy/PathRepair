a = int(input())
b = input()
c1 = b.count('o')
c2 = b.count('n')
c3 = b.count('e')
one = min(c1,c2,c3)
toone = '1 '*one

z1 = b.count('z')
z2 = b.count('e')
z3 = b.count('r')
z4 = b.count('o')
zero = min(z1,z2,z3,z4)
tozero = '0 '*zero
print(toone,tozero)


