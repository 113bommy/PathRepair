N,A,B=map(int,input().split())


a=(N//(A+B))
b=min(A,N%(A+B))

print(a*A+b)
