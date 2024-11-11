from math import gcd
z=range(1,1+int(input()))
y=0
for a in z:
  for b in z:
    for c in z:
      y+=gcd(gcd(a,b),c)
print(y)
