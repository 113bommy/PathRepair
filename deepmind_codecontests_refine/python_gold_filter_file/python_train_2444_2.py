
dx=[-1,1,0,0]
dy=[0,0,1,-1]

def valid(x,y,i,j):
    if x>=n or y>=m or x<0 or y<0:
        return False
    if (i==x and j==y) :
        return False
    return True

def DFS(i,j,parX,parY):
    v[i][j]=True
    stack=[[i,j,-1,-1]]
    while stack:
       
        a=stack.pop()
        A,B,parX,parY=a
        
        for k in range(4):
            newA,newB=A+dx[k],B+dy[k]
           
           
            if valid(newA,newB,parX,parY):
                if l[newA][newB]==l[A][B]:
                    if v[newA][newB]:
                        
                        return True
                    stack.append([newA,newB,A,B])
                    v[newA][newB]=True              
                    
        
    return False
                

                
n,m=map(int,input().split())
l=[]
for i in range(n):
    s=list(input())
    l.append(s)
c=0   
v=[[False for i in range(m)] for j in  range(n)]

for i in range(n):
    for j in range(m):
        if not v[i][j]:
            ans=DFS(i,j,-1,-1)
            if ans:
                print('Yes')
                c=1
                break
    if c:
        break
if c==0:
    print('No')
