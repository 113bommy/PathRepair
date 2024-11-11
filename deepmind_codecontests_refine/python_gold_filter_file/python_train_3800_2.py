n,x=input().split()
n,x=int(n),int(x)
cnt=0
for i in range(1,n+1):
    if x%i==0 and x//i<=n:
        cnt+=1
print(cnt)