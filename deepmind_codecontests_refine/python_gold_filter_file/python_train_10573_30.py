a,b,c,d=map(int,input().split())
z=min(a,c,d)
print(min(b,a-z)*32+z*256)