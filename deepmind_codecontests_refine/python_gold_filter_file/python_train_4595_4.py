w,h = map(int,input().split())
u1,d1 = map(int,input().split())
u2,d2 = map(int,input().split())
if d2>d1:
    d1,d2=d2,d1
    u1,u2=u2,u1
for i in range(h,d1-1,-1):
    w+=i
w-=u1
if (w<0):
    w = 0
for i in range(d1-1,d2-1,-1):
    w+=i
w-=u2
if (w<0):
    w =0
for i in range(d2-1,0,-1):
    w+=i
print(w)

