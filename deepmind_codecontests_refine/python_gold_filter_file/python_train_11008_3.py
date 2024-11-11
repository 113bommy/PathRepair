a = int(input())

if a>=100:
	yuz = int(a/100)
	yirmi = int((a%(100*yuz))/20)
	on = int((a%(100*yuz+20*yirmi))/10)
	bes = int((a%(100*yuz+20*yirmi+on*10))/5)
	bir = int((a%(100*yuz+20*yirmi+on*10+bes*5))/1)
	print(bir+bes+on+yirmi+yuz)
elif a>=20:
	yirmi = int(a/20)
	on = int((a%(20*yirmi))/10)
	bes = int((a%(20*yirmi+on*10))/5)
	bir = int((a%(20*yirmi+on*10+bes*5))/1)
	print(bir+bes+on+yirmi)
elif a>=10:
	on = int(a/10)
	bes = int((a%(on*10))/5)
	bir = int((a%(on*10+bes*5))/1)
	print(bir+bes+on)
elif a>=5:
	bes = int(a/5)
	bir = int((a%(bes*5))/1)
	print(bir+bes)
elif a>=1:
	print(a)
	

