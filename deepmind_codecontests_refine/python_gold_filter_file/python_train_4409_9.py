n,m=map(int,input().split())
# for i in range(n):
# 	# if 
# 	l=list(input())
# 	c,d=0,0
# 	l1=[]
# 	# for j in range(m):
# 	# while c==2:
# 	if l.count('*')==1:
# 		l1.append(l.index('*'))
# 		# c=i+1
# 		print(i+1,end=' ')
# 	if l.count('*')==2:
# 		for j in range(len(l)):
# 			if l[j]=='*':
# 				# if i==a:
# 				# 	continue
# 				l1.append(j+1)
# 				# c=3
# 	for i in range(len(l1)):
# 		if l1.count(l1[i])==1:
# 			print(l1[i])


					# pass
		# if l.index('*')==a:
			# continue
					# print(l.index('*')+1)
l,d=[],0
for i in range(n):
	l1=list(input())
	l.append(l1)
# print(l)
for i in range(n):
	if l[i].count('*')==1:
		print(i+1,end=' ')
	for j in range(m):
		if l[i][j]=='*':
			d+=j
	if l[i].count('*')==1:
		d-=2*l[i].index('*')

print(d+1)