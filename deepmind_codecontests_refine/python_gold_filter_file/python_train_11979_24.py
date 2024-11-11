W,H,x,y,r=map(int,input().split())
if r<=(x+r)<=W and r<=(y+r)<=H:
    print("Yes")
else:
    print("No")

