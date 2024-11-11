N,K=map(int,input().split())
L=list(map(int, input().split()))
L.sort()
print(sum(L[0:K]))