n,a,b = map(int,input().split())
q = n//(a+b)
r = n%(a+b)
print(q*a + min(a,r))