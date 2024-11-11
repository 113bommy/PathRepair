s=input()
x,y=0,0
if len(s)%2:
	print(-1)
else:
	for i in s:
		if i=='U': y+=1
		if i=='D': y-=1
		if i=='L': x-=1
		if i=='R': x+=1
	print( (abs(x)+abs(y))//2)