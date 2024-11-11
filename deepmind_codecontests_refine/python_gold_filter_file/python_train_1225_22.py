N,K=map(int,input().split())
L=list(map(int,input().split()))
L=sorted(L)
print(sum(L[:K]))