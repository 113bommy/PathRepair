a,b = input().split()

for i in range(int(a),int(b)+1):
	flag = 0
	st = str(i)
	strr = list(st)
	sts = set(strr)
	if len(sts)==len(strr):
		flag=1
		str1 = ''.join(strr)
		print(str1)
		break
if flag==0:
	print(-1)
		
