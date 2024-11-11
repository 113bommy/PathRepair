n,m = map(int,input().split())
gcd = m//n
while n*gcd != m:
  gcd = m//n
  n = 1 + (m-1)//gcd
print(gcd)