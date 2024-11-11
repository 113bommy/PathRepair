def MAP(): return list(map(int,input().split()))
def INT(): return int(input())
def FLOAT(): return float(input())
MOD = 10**9+7

x,y,z,k = MAP()
a = MAP()
b = MAP()
c = MAP()

a.sort()
b.sort()

l = []
for i in a:
    for j in b:
        l.append(i+j)

l.sort()
c.sort()
l2 = []
for i in l[-k:]:
    for j in c[-k:]:
        l2.append(i+j)

l2.sort(reverse = True)
for i in l2[:k]:
    print(i)