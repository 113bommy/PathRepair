N=int(input())
n=N-1
ans=1
for a in range(1,n):
    ans+=n//a
print(ans)
