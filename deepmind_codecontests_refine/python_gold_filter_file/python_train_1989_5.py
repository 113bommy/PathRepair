n = int(input())
m = int(input())
s = [int(input()) for _ in range(n)]
ma = max(s)+m
s = sorted(s)
pp = max(s)
for i,e in enumerate(s):
    s[i] += (pp-e)
    m -= (pp-e)
    if m<0:
        t = abs(m)
        s[i] -= t
    if m<=0:
        break
mi = max(s)
if m>0:
    mi = s[0]+(m//len(s))+(1 if m%len(s)!=0 else 0)
print(mi,ma)