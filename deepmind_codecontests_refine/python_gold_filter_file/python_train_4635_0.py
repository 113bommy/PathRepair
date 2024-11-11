h,w = [int(i) for i in input().split()]
maxx = 2005
ver = [[0]*maxx for j in range(maxx)]
hor = [[0]*maxx for j in range(maxx)]
s = []
for i in range(h):
    s.append(input())

for x in range(h):
    for y in range(w):
        hor[x+1][y+1] = hor[x][y+1]+hor[x+1][y]-hor[x][y]
        ver[x+1][y+1] = ver[x][y+1]+ver[x+1][y]-ver[x][y]
        if (s[x][y]!='.'):continue
        if (y!=w-1 and s[x][y+1]=='.'): hor[x+1][y+1]+=1
        if (x!=h-1 and s[x+1][y]=='.'): ver[x+1][y+1]+=1

q = int(input())
ans = []
#print(hor[1][1])
print()
for _ in range(q):
    x,y,x1,y1 = [int(i) for i in input().split()]
    a = 0
    a+=hor[x1][y1-1]-hor[x1][y-1]-hor[x-1][y1-1]+hor[x-1][y-1]
    a+=ver[x1-1][y1]-ver[x1-1][y-1]-ver[x-1][y1]+ver[x-1][y-1]
    ans.append(a)
for i in ans:
    print(i)