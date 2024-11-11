n=input()
n=n[::-1]
a='O-|-OOOO'
j=0
  # 'O-|OOO-O'
for i in n:
	b=list(a)
	if int(i)<5:
		b[3+int(i)]=a[3]
		if int(i)>0:
			b[3]=a[0]
	else:
		j=int(i)-5
		b[3+j]=a[3]
		if j>0:
			b[3]=a[0]
		b[0]=a[1]
		b[1]=a[0]
	str=""
	print(str.join(b))
