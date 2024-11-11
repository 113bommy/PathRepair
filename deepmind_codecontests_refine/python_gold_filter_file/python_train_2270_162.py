N, K = map(int, input().split())
S = input()
K -= 1
print(S[:K] + S[K].lower() + S[K+1:])