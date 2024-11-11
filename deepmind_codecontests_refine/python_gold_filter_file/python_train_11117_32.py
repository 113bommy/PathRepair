N, M=map(int,input().split())
if M==0:
	print("0 0")
else:
	ac=0
	pe=0
	ch=[0]*N
	Ch=[0]*N
	for i in range(M):
		a, b=input().split()
		a=int(a)-1
		if ch[a]==1:
			continue
		elif b=="WA":
			Ch[a]+=1
		else:
			ch[a]=1
			ac+=1
			pe+=Ch[a]
	print(ac,pe)

