n,k = [int(x) for x in input().split()]
s=list(input())
if k>0:
	if k==1 and n==1:
		print(0)
	else:	
		if s[0]!='1':
			s[0]='1'
			k-=1
		if n>=k:
			for i in range(1,n):
				if k<=0:
					break
				elif k>0 and s[i]!='0':
					s[i]='0'
					k-=1
		print("".join(s))

else:
	print("".join(s))
