import math
n = int(input())
if n==1:
	print ("codeforces")
elif n==2:
	print ("codeforcess")
elif n==3:
	print ("codeforcesss")
else:
	s = "codeforces"
	for i in range(1,40):
		for j in range(10):
			count = (i**(10-j))*((i+1)**j)
			if count>=n:
				break
		if count>=n:
			break
	ans = ""
	l = 0
	for k in range(10-j):
		ans += s[l]*i
		l += 1
	for k in range(j):
		ans += s[l]*(i+1)
		l += 1
	print (ans)