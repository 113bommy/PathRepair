X=list(map(int,input().split()))
sum=0
while X[1]!=0 and X[0]!=0:
    sum+=int(X[1]/X[0])
    X[1]=int(X[1]%X[0])
    X[0]-=1
print(str(int(sum)))