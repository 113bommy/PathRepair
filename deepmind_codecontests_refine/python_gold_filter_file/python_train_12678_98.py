n,a,b=map(int,input().split())
t= n//(a+b)
s = n%(a+b)
print(t*a + min(s,a))