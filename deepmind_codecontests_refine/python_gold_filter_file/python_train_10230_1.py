def calc(a,b,s):
	t=0
	for i in range(len(s)):
		if((t&1) and s[i]==b):
			t+=1
		elif((t&1)==0 and s[i]==a):
			t+=1
	return len(s)-((t//2)*2)

for _ in range(int(input())):
	s=input()
	ans=1000000
	for i in range(0,10):
		temp=s.count(str(i)[0])
		if((temp&1)==0):
			temp-=1
		ans=min(ans,len(s)-temp)
		ans=min(ans,calc('0',str(i),s))
	for i in range(10,100):
		s1=str(i)
		a=s1[0]
		b=s1[1]
		ans=min(ans,calc(a,b,s))
	print(ans)

