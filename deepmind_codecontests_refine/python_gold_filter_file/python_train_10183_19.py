N,K=map(int,input().split())
sushi=[]
for i in range(N):
    t,d=map(int,input().split())
    sushi.append((t,d))
sushi.sort(key=lambda x:(x[0],-x[1]))
#print(sushi)
X=[sushi[0][1]]
Y=[]
for i in range(1,N):
    if sushi[i-1][0]==sushi[i][0]:
        Y.append(sushi[i][1])
    else:
        X.append(sushi[i][1])
X.sort(reverse=True)
Y.sort(reverse=True)
SX=[0]
SY=[0]
for i in X:
    SX.append(SX[-1]+i)
for i in Y:
    SY.append(SY[-1]+i)
ans=0
#print(X)
#print(Y)
#1<=x<len(X)
#K-len(Y)<=x<=
for x in range(max(1,K-len(Y)),min(len(SX),K+1)):
    ans=max(SX[x]+SY[K-x]+x*x,ans)
print(ans)