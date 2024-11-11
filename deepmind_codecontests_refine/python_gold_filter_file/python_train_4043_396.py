a,b,x = map(int,input().split())
print(["NO","YES"][(a+b>=x)*(x>=a)])