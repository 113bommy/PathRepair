N,K=map(int,input().split())
S=input()
K=K-1
print(S[0:K]+S[K].lower()+S[K+1:])