N,A,B=map(int,input().split())
ans=N//(A+B)*A
X=N%(A+B)
ans+=min(X,A)
print(ans)