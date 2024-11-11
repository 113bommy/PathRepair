import math


def nCr(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
n = int(input())
l = []

f, c, sum, g1, g2 = (0,)*5

for line in range(n):
    l.append(input()[0])


my_dict = {i:l.count(i) for i in l}
#print(my_dict)


for letter, j in my_dict.items():
 g1, g2 = (0,)*2

 if j!=1:
    f = math.floor(j/2)
    c = math.ceil(j/2)
    if f != 1:
        g1 = nCr(f, 2)
    if c != 1:
        g2 = nCr(c, 2)
    sum += int(g1+g2)
print(sum)





