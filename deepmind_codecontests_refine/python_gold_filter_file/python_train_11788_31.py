n=int(input())
for i in range(n):
	st=input()
	l1=[]
	count=0
	for i in range(len(st)):
		if st[i]=="1":
			l1.append(i)
	if len(l1)>1:
		for i in range(len(l1)-1):
			count+=abs(l1[i]-l1[i+1])-1
	print(count)