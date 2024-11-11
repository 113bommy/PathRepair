from sys import stdin,stdout,stderr
n=int(input())
Map=[[] for i in range(n)]
for i in range(n):
    Map[i]=[int(x) for x in input().split()]
col=[sum(Map[x]) for x in range(n) ]
indexl=0
indexr=0
target=0
if n==1:
    print("1")
    exit()
for i in range(n):
    for j in range(n):
        if Map[i][j]==0:
            indexl=i
            indexr=j
            break
for i in range(n):
    if i!=indexl:
        target=col[i]-col[indexl]
        break
if target<0:
    print("-1")
    exit()
ans=target
Map[indexl][indexr]=target
col=[sum(Map[x]) for x in range(n) ]
row=[]
for i in range(n):
    x=0
    for j in range(n):
        x+=Map[j][i]
    row.append(x)    
left=sum(Map[x][x] for x in range(n))
right=sum(Map[x][n-x-1] for x in range(n))

target=col[0]
for element in col:
    if element!=target:
        print("-1")
        exit()
for element in row:
    if element!=target:
        print("-1")
        exit()
if target!=left or target!=right or ans==0:
    print("-1")
    exit()
print(ans)
