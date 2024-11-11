a,b,c,d=map(int,input().split())
R=0
if c<d:R=d-c
if R>c or c>d*2:exit(print(-1))
c+=R
b*=2
a*=2
if b<=d*2 :exit(print(-1))
print(a)
print(b)
print(c)

