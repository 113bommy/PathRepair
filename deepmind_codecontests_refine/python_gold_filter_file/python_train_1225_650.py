N,K=map(int,input().split())
n=list(map(int, input().split()))
m=sorted(n)
print(sum(m[0:K]))