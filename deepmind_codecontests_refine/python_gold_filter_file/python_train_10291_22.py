x,y=map(int,input().split())

G = [0,1,3,1,2,1,2,1,1,2,1,2,1]

if G[x]==G[y]:
    print("Yes")
else:
    print("No")