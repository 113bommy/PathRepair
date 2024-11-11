from fractions import gcd
n,a=map(int,input().split())
b=list(map(int,input().split())) + [a]
b.sort()
s=b[1]-b[0]
for i in range(n):
  s=gcd(b[i+1]-b[i],s)
print(s)