n,m=map(int,input().split())
M=[list(map(int,input().split())) for i in range(n)]
M1=[[0]*m for i in range(n)]

for i in range(n) :
    for j in range(m) :
        M1[i][j]=M[i][j]
l=[]
l1=[]
c=0
for i in range(n) :
    V=min(M[i])
    if n>m :
        c=1
        break
    for j in range(V) :
        l.append(['row',i+1])
    for j in range(m) :
        M[i][j]=M[i][j]-V
    for j in range(m) :
        V=M[i][j]
        for j1 in range(V) :
            l.append(['col',j+1])
        for j1 in range(n) :
            M[j1][j]=M[j1][j]-V
for i in range(n) :
    if c==1 :
        break
    if M[i].count(0)!=m :
        print(-1)
        exit()
if n<=m :
    print(len(l))
    for i in range(len(l)) :
        print(*l[i])
    exit()
for i in range(m) :
    ma=100000
    for j in range(n) :
        if ma>M1[j][i] :
            ma=M1[j][i]
    for j in range(ma) :
        l1.append(['col',i+1])
    for j in range(n) :
        M1[j][i]=M1[j][i]-ma
    for j in range(n) :
        V=M1[j][i]
        for j1 in range(V) :
            l1.append(['row',j+1])
        for j1 in range(m) :
            M1[j][j1]=M1[j][j1]-V
            

for i in range(n) :
    if M1[i].count(0)!=m:
        print(-1)
        exit()

print(len(l1))
for i in range(len(l1)) :
    print(*l1[i])
