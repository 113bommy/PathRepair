n,a = map(int,input().split())
d = list(map(int,input().split()))
x = sum(d)
b = []
for i in range(n):
    x -= d[i]
    dif = 0
    if a>x:
        dif = a-x-1
    if a-n+1<d[i]:
        dif += d[i]-a+n-1
    if x==0:
        dif = d[i]-1
    b.append(dif)
    x += d[i]
print(' '.join(map(str,b)))