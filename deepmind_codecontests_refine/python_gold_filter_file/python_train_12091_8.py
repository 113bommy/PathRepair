n, m, k=list(map(int,input().split(' ')))
a=list(map(int,input().split(' ')))

mm=max(a)

if a.count(mm)>1:
	print(mm*m)
else:
	a.remove(mm)
	mn=max(a)
	print((m//(k+1))*(mm*k+mn)+(m%(k+1))*mm)
		