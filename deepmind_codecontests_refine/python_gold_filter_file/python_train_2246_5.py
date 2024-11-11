def rev(n):
	ans=0
	while n>0:
		rem=(n%10)
		ans=(ans*10)+rem
		n//=10
	return ans

def remove_zeros(n):
	ans=0
	while n>0:
		rem=(n%10)
		if rem!=0:
			ans=(ans*10)+rem
		n//=10
	ans=rev(ans)
	return ans

a=int(input())
b=int(input())
c=a+b
a=remove_zeros(a)
b=remove_zeros(b)
c=remove_zeros(c)
if a+b==c:
	print('YES')
else:
	print('NO')