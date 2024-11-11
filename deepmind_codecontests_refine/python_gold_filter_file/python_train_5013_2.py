#codeforces1156B
gi = lambda : list(map(int,input().strip().split()))
for k in range(gi()[0]):
	s = list(input())
	ans = []
	s.sort()
	ans.append(s.pop(0))
	flag = False
	while s:
		flag = True
		for j in range(len(s)):
			if abs(ord(s[j]) - ord(ans[-1])) != 1:
				ans.append(s.pop(j))
				flag = False
				break;
			if abs(ord(s[j]) - ord(ans[0])) != 1:
				ans.insert(0, s.pop(j))
				flag = False
				break;
			for i in range(1, len(ans)):
				if abs(ord(ans[i]) - ord(s[j])) != 1 and abs(ord(ans[i-1]) - ord(s[j])) != 1:
					ans.insert(i, s.pop(j))
					flag = False
					break;
		if flag:
			break;
	if flag:
		print("No answer")
	else:
		print("".join(ans))