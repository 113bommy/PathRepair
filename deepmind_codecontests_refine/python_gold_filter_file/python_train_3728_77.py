from itertools import product

x,y,z,k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
d = sorted([s+t for s,t in product(a,b)], reverse=True)[:3000]
e = sorted([s+t for s,t in product(c,d)], reverse=True)[:k]
[print(i) for i in e]
