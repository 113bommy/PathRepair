t=int(input())
for sdaskljdkj in range(t):
	n,k=[int(i)for i in input().split()]
	l=[int(i)for i in input().split()]
	ans=""
	last=k
	for i in range(n-1):
		if last>=10**(l[i+1]-l[i])-1:
			ans="9"*(l[i+1]-l[i])+ans
			last-=int('9'*(l[i+1]-l[i]))
		else:
			ans=str(last+1)+ans
			last=-1
			break
	if(last==-1):
		print(ans)
	else:
		print(str(last+1)+ans)
