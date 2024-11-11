n,m= map(int, input().split())
count=0
mat=[]
for i in range(n):
    temp= input()
    temp= list(temp)
    mat.append(temp)
count=0
for i in range(n):
    wasbest=False
    for j in range(m):
        isbest= True
        for k in range(n):
            if mat[k][j]>mat[i][j]:
                isbest=False
        if isbest:
            wasbest=True
    if wasbest:
        count+=1

print(count)