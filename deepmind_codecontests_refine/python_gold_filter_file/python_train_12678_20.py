n,a,b=map(int,input().split())
p=n//(a+b)
q=n%(a+b)
print( p*a+min(q,a) )