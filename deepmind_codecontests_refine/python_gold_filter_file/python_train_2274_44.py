import fractions
n,k = map(int,input().split())
a = sorted(list(map(int,input().split())))
a_max = max(a)
a_gcd = a[0]
for i in range(n):
  a_gcd = fractions.gcd(a_gcd,a[i])
if k <= a_max and k % a_gcd == 0:
  print("POSSIBLE")
else:
  print("IMPOSSIBLE")