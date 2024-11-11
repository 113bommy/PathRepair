N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))+[0]
ans=c=0
for i in range(N+1):
    a=A[i]
    b=B[i]
    ans+=min(a,c)
    a=max(a-c,0)
    ans+=min(a,b)
    c=max(b-a,0)
print(ans)
