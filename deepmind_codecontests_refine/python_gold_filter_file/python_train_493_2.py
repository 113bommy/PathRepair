N=int(input())
ans=0
for b in range(1,N):
    ans+=(N-1)//b
print(ans)