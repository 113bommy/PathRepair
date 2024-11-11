X,N=map(int,input().split())
p=list(map(int,input().split()))

Q=[0]*102
for i in range(0,102):
    Q[i]=abs(X-i)


for i in  p:
    Q[i]=1000

print(Q.index(min(Q)))