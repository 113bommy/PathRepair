k,s=map(int,input().split())
n=sum(0<=s-i-j<=k for i in range(k+1) for j in range(k+1))
print(n)