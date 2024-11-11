for t in range(int(input())):
	a,b,c,d=map(int,input().split(' '))
	l,x,y,o=(a+b)//(min(a,b)+1),0,0,""
	if a*l<=b:y=a+b
	elif b*l<=a:x=a+b
	else:x,y=(a*l-b)//(l-1),(b*l-a)//(l-1)
	for i in range(c,d+1):o+="AB"[i%(l+1)==0] if i<=x else "BA"[(a+b-i+1)%(l+1)==0] if a+b-i+1<=y else "AB"[a-x+x//(l+1)-y//(l+1)==0]
	print(o)