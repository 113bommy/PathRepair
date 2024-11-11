def help():
	n = int(input())
	s1 = list(input())
	s2 = list(input())
	if(s1 == s2):
		print(0)
		return
	if(s1.count('1')!=s2.count('1')):
		print("-1")
		return
	operate = []
	for i in range(n):
		if(s1[i] != s2[i]):
			operate.append(1 if s1[i] == '1' else -1)

	ll = len(operate)
	op1 = [0]*ll
	op1[0] = operate[0]
	for i in range(1,ll):
		op1[i] = operate[i] + op1[i-1]
	ans = abs(max(op1)-min(op1))
	print(ans)
help()