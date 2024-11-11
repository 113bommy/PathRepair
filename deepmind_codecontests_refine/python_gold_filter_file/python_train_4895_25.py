n=int(input())
m=int(input())
d=-10**9

for i in range(n-1):
    x=int(input())
    d=max(x-m,d)
    m=min(m,x)
print(d)
