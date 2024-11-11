MOD = 1000000007
MOD2 = 998244353
ii = lambda : int(input())
si = lambda : input()
dgl = lambda : list(map(int, input()))
f = lambda : map(int, input().split())
il = lambda : list(map(int, input().split()))
ls = lambda : list(input())
n, m = f()
l = []
c=0
for i in range(n):
    a, *b = f()
    b = set(b)
    if len(b):
        l.append(b)
    else:
        c+=1
bl=[0]*len(l)
for i in range(len(l)):
    if bl[i] == 0:
        x = l[i]
        for j in range(i, len(l)):
            for k in range(i, len(l)):
                if bl[k] == 0 and len(x.intersection(l[k])):
                    x = x.union(l[k])
                    bl[k] = i + 1

print(max(0,len(set(bl))-1)+c)