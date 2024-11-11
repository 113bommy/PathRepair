N,K=map(int,input().split())
S=list(input())
T=S[K-1]
S[K-1]=T.lower()
print("".join(S))