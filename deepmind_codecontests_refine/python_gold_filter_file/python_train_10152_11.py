import math
vstup = input()
seznam = [int(n) for n in vstup.split()]
l = seznam[0]
r = seznam[1]
k = seznam[2]
a = math.log(l,k)
b = math.log(r,k)
y = int(b-a)
d = False
for c in range (y+3):
    x = k**(int(a+c-1))
    if x >= l and x <= r:
        print(x)
        d = True
if d == False:
    print(-1)
print(end = " ")
