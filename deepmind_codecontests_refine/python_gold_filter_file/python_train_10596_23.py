n,k=map(int,input().split())
cnt=1
while n>=k:
    n//=k
    cnt+=1
print(cnt)
