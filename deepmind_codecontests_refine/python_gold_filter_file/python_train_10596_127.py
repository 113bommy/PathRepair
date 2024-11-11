N,K=map(int,input().split())
cnt=0
while(N>0):
    N//=K
    cnt+=1
print(cnt)