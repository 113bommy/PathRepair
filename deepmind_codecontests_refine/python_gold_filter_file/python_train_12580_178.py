N,K=map(int,input().split())
S=list(map(int,input().split()))
S.sort()
print(sum(S[-K:]))