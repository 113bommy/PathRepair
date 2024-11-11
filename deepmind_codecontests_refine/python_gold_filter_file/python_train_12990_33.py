a,b,n=map(int,input().split())
m=min(n,b-1)
tmp=(a*m//b)-((m//b)*a)    
print(tmp)