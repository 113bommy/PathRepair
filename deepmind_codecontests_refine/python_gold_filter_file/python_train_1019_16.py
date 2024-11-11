N=int(input())
S=input()
M=S.count('.')
ans=M

for i in range(N):
	if S[i] == '#':
		M = M+1
	else:
		M = M-1
	ans = min(M,ans)
print(ans)