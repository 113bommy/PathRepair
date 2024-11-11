X,Y=map(int,input().split())
cnt=0
while(Y>=X):
    X*=2
    cnt+=1
print(cnt)