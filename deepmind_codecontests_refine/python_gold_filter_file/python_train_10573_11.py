a,b,c,d=map(int, input().split())
x=min(a,c,d)
print(min(b,a-x)*32 + x*256)