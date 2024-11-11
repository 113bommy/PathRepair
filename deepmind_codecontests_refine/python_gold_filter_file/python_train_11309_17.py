import sys
input=sys.stdin.buffer.readline

n=int(input())
a=int(input())
b=int(input())
if n%a==0 or n%b==0 or n%(a+b)==0:
	print("YES")
	if n%a==0:
		print(n//a,0)
	elif n%b==0:
		print(0,n//b)
	else:
		print(n//(a+b),n//(a+b))
else:
	rest=n%(a+b)
	ans=n//(a+b)
#	print(rest,ans)
	if rest%a==0 or rest%b==0:
		print("YES")
		if rest%a==0:
			print(ans+(rest//a),ans)
		else:
			print(ans,ans+(rest//b))
	else:
		isprinted=False
		i=0
		while i<n and (n-i*a)>=0:
			if (n-(i*a))%b==0:
				print("YES")
				print(i,(n-(i*a))//b)
				isprinted=True
				break
			i+=1
		if isprinted==False:
			print("NO")