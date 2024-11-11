W,H,x,y,r= map(int, input().split())
if W>=x+r and r<=x and r<=y and H>=y+r:
 print ("Yes")
else:
 print ("No")