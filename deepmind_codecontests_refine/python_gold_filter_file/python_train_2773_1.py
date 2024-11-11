x = int(input())
hh,mm = map(int,input().split())
a = 0
while hh%10!=7 and mm%10!=7:
	mm-=x
	if mm<0:
		mm = 60 + mm
		hh-=1
		if hh<0:
			hh=23
	a+=1
print(a)