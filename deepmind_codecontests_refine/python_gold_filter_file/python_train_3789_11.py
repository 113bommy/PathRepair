import sys
n,m=map(int,sys.stdin.readline().split())

L=list(map(int,sys.stdin.readline().split()))
c=0
Ans=""
for i in range(m):
    x=list(map(int,sys.stdin.readline().split()))
    if(x[0]==1):
        L[x[1]-1]=x[2]-c
    elif(x[0]==2):
        c+=x[1]
    else:
        Ans+=str(L[x[1]-1]+c)+"\n"
sys.stdout.write(Ans)
