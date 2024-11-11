n,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
g=a[-1]
def gcd(a,b):
  while b:a,b=b,a%b
  return a
for i in a:g=gcd(g,i)
if a[-1]<k or k%g!=0:print("IMPOSSIBLE")
else:print("POSSIBLE")