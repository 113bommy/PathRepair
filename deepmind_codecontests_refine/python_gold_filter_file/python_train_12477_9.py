x=int(input())
for i in range(1,10**9+1):
	if (i+1)*i*0.5>=x:
		print(i)
		break