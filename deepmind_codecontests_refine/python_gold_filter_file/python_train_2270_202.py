N,K=(int(i) for i in input().split())
S=input()
print(S[:K-1]+S[K-1].lower()+S[K:])