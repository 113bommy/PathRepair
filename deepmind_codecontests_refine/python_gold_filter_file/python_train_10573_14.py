a,b,c,d = map(int,input().split())
x = min(a,c,d)
y= min(b,a-x)
print(x*256 + y* 32)