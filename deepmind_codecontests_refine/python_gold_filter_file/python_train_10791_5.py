n = int(input())
lis = list(map(int,input().split()))
if n < 3:
	print(0)
else:
	an = lis[-1]
	a = lis[0]
	ds = (lis[-1] - lis[0])//(n-1)
	chk = [ds,ds-1,ds+1]
	ass = [lis[0],lis[0]-1,lis[0] + 1]
	ans = []
	for j in range(3):
		for k in range(3):
			mark = True
			i = 0
			dif=[]
			while i< n :
				if abs(lis[i] - ass[j] - i*(chk[k])) < 2:
					dif.append(abs(lis[i] - ass[j] - i*(chk[k])))
				else:
					mark = False
					break
				i+= 1
			if mark: 
				ans.append(dif)
	say = 1000000
	for i in ans:
		count =0
		for j in i:
			if j==1:
				count+= 1
		say = min(say,count)
	if say==1000000:
		print(-1)
	else:
		print(say)




