if __name__ == '__main__':
	n = int(input())
	s = input()
	ans = ''
	i = 0
	while i < n:
		if len(ans) == 0:
			ans+=s[i]
		elif ans[-1] not in 'aeiouy' or s[i] not in 'aeiouy':
			ans+=s[i]
		i+=1
	print(ans)