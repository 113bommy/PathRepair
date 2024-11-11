t1,t2 = map(int,input().split())
a1,a2 = map(int,input().split())
b1,b2 = map(int,input().split())

if (a1<b1 and a2<b2) or (a1>b1 and a2>b2):
    print(0)
    exit()

if a1 > b1:
    a1,b1 = b1,a1
    a2,b2 = b2,a2

_b1 = b1 - a1
_a2 = a2 - b2

v1 = t1*_b1
v2 = t2*_a2

if v1 == v2:
    print('infinity')
    exit()

if v1 > v2:
    print(0)
    exit()

d = v2 - v1
k = v1 // d

ans = k*2 + 1
if v2*k == v1*(k+1):
    ans -= 1
print(ans)