l=[]
ans=[[0 for i in range(60)]for j in range(25)]
c=0
n=int(input())
for i in range(n):
    a,b=map(int,input().split())
    ans[a][b]+=1
for i in range(0,24):
    for j in range(0,60):
        if ans[i][j]>c:
            c=ans[i][j]
print(c)            
