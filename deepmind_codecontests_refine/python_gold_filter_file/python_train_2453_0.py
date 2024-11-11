a = {'monday':0,'tuesday':1,'wednesday':2,'thursday':3,'friday':4,'saturday':5,'sunday':6}

p = a[input()]
q = a[input()]

k = (q - p + 7)%7
if(k==0 or k==3 or k==2):
	print('YES')
else:
	print('NO')