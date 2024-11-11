
n,k = map(int,input().split())
if n==1 :
	print(1 if k==0 else -1)
else:
	pr = (n-2)//2
	k -= pr
	if k<1 :
		print(-1)
	else:
		res = []
		res += [k,2*k]
		res += list(range(2*k+1,2*k+1+2*pr))
		if n%2:
			res += [2*k+1+2*pr]
		print(*res)

#  C:\Users\Usuario\HOME2\Programacion\ACM