n , m = list(map(int,input().split()))
count = 0
for i in range(n):
	p = list(input().split())
	if p[0]=="+":
		m = m+int(p[1])	
	elif p[0]=="-":
		if int(p[1])<=m:
			m = m-int(p[1])
		elif int(p[1])>m:
			count += 1
print(m,count)			

