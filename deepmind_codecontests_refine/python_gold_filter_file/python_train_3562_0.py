from sys import stdin

class disjoinSet(object):
    def __init__(self,n):
        self.father = [x for x in range(0,n+1)]
        self.rank = [0 for x in range(0,n+1)]

    def setOf(self, x):
        if(self.father[x] != x):
            self.father[x] = self.setOf(self.father[x])
        return self.father[x]

    def Merge(self,x,y):
        xR = self.setOf(x)
        yR = self.setOf(y)
        if(xR == yR):
            return
        if self.rank[xR] < self.rank[yR]:            
            self.father[xR] = yR
            size[yR] += size[xR]
        elif self.rank[xR] > self.rank[yR]:
            self.father[yR] = xR
            size[xR] += size[yR]
        else:
            self.father[yR] = xR
            size[xR] += size[yR]
            self.rank[xR] +=1

def LessSize(x):
    return min(size[dsu.setOf(x)],size[dsu.setOf(x+k)])

def Solve(i):   
    global ans
    cant = col[i][0]
    if cant == 2:
        x = col[i][1]
        y = col[i][2]
        if S[i] == 1:
            if dsu.setOf(x) == dsu.setOf(y):
                return
            ans -=LessSize(x) + LessSize(y)
            dsu.Merge(x,y)
            dsu.Merge(x+k,y+k)
            ans +=LessSize(y)
        else:
            if dsu.setOf(x) == dsu.setOf(y+k):
                return
            ans -=LessSize(x)+LessSize(y)
            dsu.Merge(x,y+k)
            dsu.Merge(x+k,y)
            ans +=LessSize(y)    
    elif cant == 1:
        x = col[i][1]
        if S[i] == 1:
            if dsu.setOf(x) == dsu.setOf(0):
                return
            ans -=LessSize(x)
            dsu.Merge(x,0)
            ans +=LessSize(x)
        else:
            if dsu.setOf(x+k) == dsu.setOf(0):
                return
            ans -=LessSize(x)
            dsu.Merge(x+k,0)
            ans +=LessSize(x)    



n,k = map(int,input().split())
S = [1]+list(map(int,list(stdin.readline().strip())))

dsu = disjoinSet(k*2+1)
    
col = [[0 for _ in range(3)] for _ in range(n+2)]
size = [0 for _ in range(k*2+1)]
ans = 0

for i in range(1,k+1):
    c = stdin.readline()
    c = int(c)
    conjunto = [1]+list(map(int,list(stdin.readline().split())))
    for j in range(1,len(conjunto)):
        x = conjunto[j]                        
        col[x][0] = col[x][0]+1
        col[x][col[x][0]] = i


for i in range(1,k+1):
    size[i]=1
size[0]=3*10e5

for i in range(1,n+1):    
    Solve(i)
    print(ans)
