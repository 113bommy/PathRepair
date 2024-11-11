n,k=map(int,input().split())
cnt=0
while(n>0):
    n//=k
    cnt+=1
print(cnt)