from sys import stdin
def ii(): return int(stdin.readline())
def mi(): return map(int, stdin.readline().split())
def li(): return list(mi())
n=ii()
a=li()
x=z=0
m=max(a)
mm=a.index(m)
for i in range(n):
    if a[i]%2:
        x+=1
    if i!=mm and z<m:
        z+=a[i]
x=x%2
if z<m:
    x=1
print(['YES', 'NO'][x])