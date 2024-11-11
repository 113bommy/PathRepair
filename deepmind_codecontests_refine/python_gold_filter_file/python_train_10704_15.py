N = int(input())
S = input()
ans = [S[1:].count("E")]
for i in range(1, N):
	tmp = ans[i - 1]
	if S[i - 1] == "W":
		tmp += 1
	if S[i] == "E":
		tmp -= 1
	ans.append(tmp)
print(min(ans))
