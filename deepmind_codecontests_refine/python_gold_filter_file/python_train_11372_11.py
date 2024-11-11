u,v=map(int,input().split())
bits=[0]*61
i=0
if u&1 != v&1:
	print(-1)
else:
	c=0
	while(u or v):
		a=u&1
		b=v&1
		if a==1 and b==1:
			bits[i]+=1
			if c==1:
				bits[i-1]+=2
		
		elif a==1 and b==0:
			bits[i]+=1
			if c!=1:
				bits[i-1]+=2
				c=1


		elif a==0 and b==1:
			if c!=1:
				bits[i-1]+=2
			else:
				c-=1
		elif a==0 and b==0:
			if c==1:
				bits[i-1]+=2

		i+=1
		u>>=1
		v>>=1
	if c!=0:
		print(-1)
	else:
		mbit=max(bits)
		A=[]
		for j in range(mbit):	
			s=""
			for i in range(len(bits)):
				if bits[i]>=j+1:
					s='1'+s
				else:
					s='0'+s
			A.append(int(s,2))
			
		print(mbit)
		print(*A)


