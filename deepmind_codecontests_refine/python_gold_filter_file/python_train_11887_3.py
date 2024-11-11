n=int(input())
if n%2!=0:
	print('YES');lst=[1];mst=[];
	for x in range(2,2*n+1,2):
		if x%4==0:
			lst.append(x);lst.append(x+1)
		else:
			mst.append(x);mst.append(x+1)
	print(*lst,*mst[:n])
else:
	print('NO')