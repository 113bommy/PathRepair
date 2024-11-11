from collections import Counter

N,V = map(int,input().split())
cnt = 0

a = tuple(map(int,input().split()))
b = tuple(map(int,input().split()))
c = tuple(map(int,input().split()))
d = tuple(map(int,input().split()))

ab = Counter(ai+bi for ai in a for bi in b)
cd = Counter(ci+di for ci in c for di in d)

cnt = sum(ab[V-i]*t for i,t in cd.items() if V-i in ab)

print(cnt)