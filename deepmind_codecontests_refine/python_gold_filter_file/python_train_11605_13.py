n,m=map(int,input().split())
while m%2==0:m/=2
if n%m==0: print("Yes")
else:print("No")