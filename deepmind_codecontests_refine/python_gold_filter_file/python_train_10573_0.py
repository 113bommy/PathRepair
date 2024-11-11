a,b,c,d = map(int,input().split())
m1 =min(a,c,d) 

s=m1*256
if (a-m1)>=b:
    s=s+(b*32)
else:
    s=s+(a-m1)*32
print(s)