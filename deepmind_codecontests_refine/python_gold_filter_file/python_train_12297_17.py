from math import ceil as c 
for x in range(int(input())):
	a,b=map(int,input().split())
	if a==b:
		if a%2==0:
			print(a)
		else:
			print(-a)
	elif a%2!=0 and b%2!=0:
		print(((b-a)//2)-b)
	elif a%2==0 and b%2==0:
		print(-((b-a)//2)+b)
	elif a%2==0 and b%2!=0:
		print(-(c((b-a)/2)))
	elif a%2!=0 and b%2==0:
		print(c((b-a)/2))