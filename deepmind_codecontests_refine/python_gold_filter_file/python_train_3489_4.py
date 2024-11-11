R = lambda : map(int, input().split())
n = int(input())
p = []
for i in range(n):
    x,y = R()
    p.append((x,y,i+1))
p = sorted(p)

for i in range(n-2):
    p1 = (p[i+1][0]-p[i][0],p[i+1][1]-p[i][1])
    p2 = (p[i+2][0]-p[i][0],p[i+2][1]-p[i][1])
    if p1[0]*p2[1]!=p1[1]*p2[0]:        
        print(p[i][2],p[i+1][2],p[i+2][2])
        exit()
