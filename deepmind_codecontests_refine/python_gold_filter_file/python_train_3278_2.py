a = list(input())

if(len(a) <= 2):
	if(len(a) == 1):
		if(int(a[0])%8 == 0):
			print('YES')
			print(a[0])
		else:
			print('NO')
	else:
		if(int(''.join(a))%8 == 0):
			print('YES')
			print(''.join(a))
		else:
			if(int(a[0])%8 == 0):
				print('YES')
				print(a[0])
			elif(int(a[1])%8 == 0):
				print('YES')
				print(a[1])
			else:
				print('NO')
else:
	ans = None
	def recur(a, i, dp):
		global ans
		#print(len(dp), end = ' ')
		if(i >= len(a) or len(a) == 0):
			return False
		if(''.join(a) in dp):
			return dp[''.join(a)]
		temp = a.copy()
		if(len(dp) > 10000):
			return False
		del temp[i]
		ind = len(temp) - 3
		tval = ''.join(temp)
		if(tval in dp):
			return dp[tval]
		elif(len(temp) > 0 and ind >= 0 and int(''.join(temp[ind:len(temp)]))%8 == 0):
			ans = tval
			return True
		elif(len(temp) > 0 and ind < 0 and int(tval) % 8 == 0):
			ans = tval
			return True
		else:
			an = recur(temp, i, dp) or recur(a, i + 1, dp)
		
		dp[tval] = an
		return an


	dp = {}
	if(int(''.join(a[len(a) - 3:len(a)]))%8  == 0):
		print('YES')
		print(''.join(a)) 
	elif(recur(a, 0, dp)):
		print('YES')
		print(ans)
	else:
		print('NO')
