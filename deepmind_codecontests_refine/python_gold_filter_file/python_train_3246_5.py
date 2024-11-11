import math
n, k = map(int, input().split())
en = math.ceil(n / 2)
l = []
for e in range(n):
    l.append(int(input()))
dzerieni = [0 for e in range(k + 1)]

for el in l:
    dzerieni[el] += 1

#print(dzerieni)
komplekti = 0
vieni = 0
for d in dzerieni:
    komplekti += d // 2
    vieni += d % 2

apmierinatie = komplekti * 2 + (vieni + 1) // 2
print(apmierinatie)



    