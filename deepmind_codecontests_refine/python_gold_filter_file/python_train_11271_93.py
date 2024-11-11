for _ in range(int(input())):
	n=int(input())
	s=input()
	ans=""
	for i in range(n):
		ans+=s[2*i]
	print(ans)