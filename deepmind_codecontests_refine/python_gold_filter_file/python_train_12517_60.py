keyword = ['H', 'Q', '9']
S = input()
ans = 'NO'
for i in range(0, len(S)):
	if S[i] in keyword:
		ans = 'YES'
		break
print(ans)