h,w=map(int,input().split())
grid=[["."]*(w+2)]+[list("."+input()+".")for i in range(h)]+[["."]*(w+2)]
for s in range(1,1+h):
    for t in range(1,1+w):
        if grid[s][t]=="#" and all([grid[s+x][t+y]=="."for x,y in ([0,-1],[0,1],[1,0],[-1,0])]):
            print("No")
            exit()
print("Yes")