N,K=[int(x) for x in input().split()]
S=input()
print(S[:K-1]+S[K-1].lower()+S[K:])