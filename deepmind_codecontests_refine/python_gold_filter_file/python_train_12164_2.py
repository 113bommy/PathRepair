from itertools import accumulate as ac
n=int(input())+2
t=[0]+list(map(int,input().split()))+[0]
v=[0]+list(map(int,input().split()))+[0]
s=[0]+list(ac(t))
def f(i,x):
    if s[i]<=x<=s[i+1]:return v[i]
    elif x<s[i]:return v[i]+s[i]-x
    else:return v[i]+x-s[i+1]
c=float("INF")
for i in range(n):
    c=min(c,f(i,0))
e=0
for i in range(1,2*s[-1]+1):
    i=i/2
    d=float("INF")
    for j in range(n):
        d=min(d,f(j,i))
    e+=0.25*(c+d)
    c=d
print(e)