x = str(input())

y = str(input())

a = ''

for i in range(len(x)):

	if x[i]==y[i]:
		a+=chr(ord(x[i]))

	elif x[i]>y[i]:
		a+=y[i]

	else:
		a = '-1'
		break


if(a[-1]!='-1'):
	print(a)

else:
	print('-1')
