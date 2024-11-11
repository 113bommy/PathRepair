N, K = map(int, input().split())
S = input()

d = 0
for i in range(N-1):
	if(S[i] != S[i+1]):
		d += 1
d = max(0, d - 2 * K)
print(N - 1 - d)