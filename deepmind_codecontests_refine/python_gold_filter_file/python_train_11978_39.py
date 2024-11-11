W,H,x,y,r = list(map(int,input().split()))
print("No" if x<r or x+r>W or y<r or y+r>H else "Yes")
