k=int(input())
if k<25:
	print(-1)
else:
	l=[]
	for i in range(5,k):
		if k%i==0 and k//i>=5:
			l.append(i)
			l.append(k//i)
			break
	if len(l)<2:
		print(-1)
	else:
		k=('aeiou'+'g'*(l[0]-5))*l[1]
		for j in range(l[1]):
			print(k[j:j+l[0]],end='')