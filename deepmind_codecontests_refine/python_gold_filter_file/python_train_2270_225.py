N,k=map(int,input().split())
S=input()
print(S[:k-1] + S[k-1].lower() + S[k:])