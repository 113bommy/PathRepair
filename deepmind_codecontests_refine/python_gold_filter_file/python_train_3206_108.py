a, b, k = map(int,input().split())
t = min(a,k)
a -= t
k -= t
u = min(b,k)
b-=u
print(a,b)