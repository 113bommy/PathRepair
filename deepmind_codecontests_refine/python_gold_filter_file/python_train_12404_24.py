n,m,r=map(int,input().split())
n1=list(map(int,input().split()))
m1=list(map(int,input().split()))
money=r
d=r
if n == 1:
    n2 = n1[0]
else:
    n2 = min(n1)
if m == 1:
    m2 = m1[0]
else :
    m2 = max(m1)

while n2<m2:
    if d>=n2:
        d= d%n2
        c=(r-(r%n2))/n2
        money = money + (m2-n2)*c
        n1.pop(n1.index(n2))
    elif d!=0 and d > n2 and n2<m2:
        d= d%n2
        c=(r-(r%n2))/n2
        money = money + (m2-n2)*c
        n1.pop(n1.index(n2))
    else:
        break
print(int(money))



