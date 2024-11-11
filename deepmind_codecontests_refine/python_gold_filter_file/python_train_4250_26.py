a,b,k=map(int,input().split())
s=[i for i in range(1,101)  if a%i==0 and b%i==0]
print(s[-k])