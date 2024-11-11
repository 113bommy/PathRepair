import sys
N,K=map(int,input().split())
D=[int(i) for i in input().split()]
L=[0]*10
for i in range(K):
    L[D[i]]=1
for i in range(N,100001):
    x=str(i)
    flag=True
    for k in range(len(x)):
        y=int(x[k])
        if L[y]==1:
            flag=False
    if flag:
        print(i)
        sys.exit()