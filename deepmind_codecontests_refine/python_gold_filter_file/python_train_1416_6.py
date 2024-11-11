h,m = list(map(int,input().split(':')))
print((h*30+m/2)%360,m*6)
