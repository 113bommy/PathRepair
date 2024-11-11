W,H,x,y = map(int,input().split())

f = 0
if x==W/2 and y==H/2:
    f = 1

print(W*H/2,f)
