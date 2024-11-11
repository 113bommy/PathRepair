n,x,m = map(int,input().split())
set_a = set()
a = []
while len(a)<n:
    if x in a:break
    set_a.add(x)
    a.append(x)
    x = x**2%m

ans = sum(a[:min(n,len(a))])
n -= len(a)
if n<1:
    print(ans)
    exit()

i = a.index(x)
l = len(a)-i
ans += sum(a[i:]) * (n//l)
n %= l
ans += sum(a[i:i+n])
print(ans)

