N,K = map(int,input().split())
S = input()

h = 0
for i in range(len(S)-1):
  if S[i] == S[i+1]:
    h += 1
h += 2*K
print(min(N-1, h))
