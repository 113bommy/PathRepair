W,H,x,y,r=map(int,input().split())
if x+r>W or y+r>H or x-r<0 or y-r<0:
    print("No")
else:
    print("Yes")