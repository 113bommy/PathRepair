N=int(input())
p=[list(map(int, input().split())) for _ in range(N)]
ax, ay, ah = list(filter(lambda x: x[2], p))[0]
for i in range(101):
  for j in range(101):
    center=[i,j,ah+abs(ax-i)+abs(ay-j)]
    if all(t[2]==max(center[2]-abs(t[0]-center[0])-abs(t[1]-center[1]),0) for t in p) :
      print(center[0],center[1],center[2])
