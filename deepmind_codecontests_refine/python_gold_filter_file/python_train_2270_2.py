N , K = [int(n) for n in input().split()]
S = input()
print(S[:K-1]+S[K-1].lower()+S[K:])