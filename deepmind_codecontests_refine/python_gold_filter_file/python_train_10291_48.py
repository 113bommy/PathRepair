x,y=map(int,input().split())
d=[0,1,3,1,2,1,2,1,1,2,1,2,1]
if d[x]==d[y]:
    print("Yes")
else:
    print("No")