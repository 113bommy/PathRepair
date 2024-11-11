#!/usr/bin/python
import sys
q = int(input())
def base3(num):
	ret = ""
	while num != 0:
		ret += str(num % 3)
		num = int(num / 3)
	ret += '0'
	return ret[::-1]
for qq in range(q):
	num = int(input())
	snum = base3(num)
	slen = len(snum)
	i = 0
	cnt = 0
	ans = ""
#	print (snum)
	while True:
#		print (ans)
		cnt += 1
		if i == slen or snum[i] == '0':
			ans += '1' * (cnt-1) + '0'
			cnt = 0
			if i == slen:
				break

		elif snum[i] == '2':
			ans = ans[:-1] + '1' + '0' * (cnt + slen - i)
			break
			cnt = 0
		i += 1

	ans = ans[:-1]
#	print (ans)
	print (int(ans, 3))
#	print()

