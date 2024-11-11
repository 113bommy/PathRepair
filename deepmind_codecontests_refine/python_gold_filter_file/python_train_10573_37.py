a,b,c,d=map(int,input().split())
y=min(a,c,d)
print(min(b,a-y)*32+y*256)