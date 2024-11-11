s=input()
W,H,x,y,r=map(int,s.split())
if(x-r>=0 and y-r>=0 and y+r<=H and x+r<=W):
    print("Yes")
else:
    print("No")