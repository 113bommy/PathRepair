k,x = map(int,input().split())
taken,given,count=x,0,0
for i in range(k):
	l=list(input().split())
	if l[0]=='+' :
		taken+=int(l[1])
	elif l[0]=='-' and taken>=int(l[1]):
		taken=taken-int(l[1])
	else:
		count+=1
print(taken,count)