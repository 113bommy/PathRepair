t=int(input())
for test in range(t):
	S=input()
	L=list(S)
	Noanswer=0
	L1=[ord(k) for k in L]
	D=[[x,L1.count(x)] for x in set(L1)]
	D.sort(key=lambda x:x[0])
	if len(D)>4:
		Dleft=[]
		Dright=[]
		for k in range(len(D)):
			if k%2==0:
				Dleft.append(D[k])
			else :
				Dright.append(D[k])
		D1= Dleft+Dright

		
	elif len(D)==4:
		D1=[D[2],D[0],D[3],D[1]]

	elif len(D)==3:
		if (D[2][0]-D[1][0]==1) and(D[1][0]-D[0][0]==1):
			Noanswer=1
		else :
			if D[1][0]-D[0][0]==1:
				D1=[D[0],D[2],D[1]]
			else :
				D1=[D[1],D[0],D[2]]

	elif len(D)==2:
		if D[1][0]-D[0][0]==1:
			Noanswer=1
		else :
			D1=D
	elif len(D)==1:
		D1=D
	if Noanswer==0:
		H=''
		for k in D1:
			for j in range(k[1]):
				H=H+chr(k[0])
		print(H)
	else :
		print('No answer')