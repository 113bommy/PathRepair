a=int(input())
z=[[0]*(a+1) for _ in " "*(a+1)];p=[0]*(a+1)
for _ in " "*(((a*(a-1))//2)-1):
    u,v=map(int,input().split());p+=[[u,v]]
    z[u][v]=1
    p[u]+=1;p[v]+=1
for i in range(1,a+1):
    for j in range(1,a+1):
        for k in range(1,a+1):
            if z[i][j]==1 and z[j][k]==1:z[i][k]=1
gh=[]
for i in range(1,a+1):
    if p[i]<a-1:gh.append(i)
if z[gh[0]][gh[1]]:print(gh[0],gh[1])
else:print(gh[1],gh[0])