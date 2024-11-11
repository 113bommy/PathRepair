N = int(input())
K = int(input())
S = 1
for i in range(N):
    S = min(2*S, S+K)
print(S)