a,b,c,d = map(int,input().split())
kmax = max(a,b,c)
kmin = min(a,b,c)
i=0
if ((kmax == a) and (kmin == b)) or ((kmax == b) and (kmin == a)):
    ks = c
elif ((kmax == b) and (kmin == c)) or ((kmax == c) and (kmin == b)):
    ks = a
else:
    ks = b
if abs(kmax-ks) < d:
    i+=abs(abs(kmax-ks)-d)
if abs(kmin-ks) < d:
    i+=abs(abs(kmin-ks)-d)
print(i)
