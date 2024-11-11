n=int(input())
a=list(map(int,input().split()))

bit=[]
for i in range(n):
	s=bin(a[i])[2:]
	if len(s)<30:s='0'*(30-len(s))+s
	bit.append(s)

def ans(p,j,an):
	if j==30:
		return(an)
	if len(p)==1:
		return(an+'0'*(30-j))
	d1=[]
	d0=[]
	for i in p:
		if bit[i][j]=='1':
			d1.append(i)
		else:d0.append(i)
	if len(d1)==0:
		return(ans(d0,j+1,an+'0'))
	elif len(d0)==0:
		return(ans(d1,j+1,an+'0'))
	return(min(ans(d1,j+1,an+'1'),ans(d0,j+1,an+'1')))

print(int(ans([i for i in range(n)],0,''),2))