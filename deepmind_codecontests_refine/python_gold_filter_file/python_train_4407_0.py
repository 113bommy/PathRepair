rr=int(input())

for g in range(rr):
	n=int(input())
	arr1=list(map(int, input().split(' ')))
	arr2=list(map(int, input().split(' ')))
	arr3=[[0,False] for i in range(n)]
	for i in range(n):
		arr3[arr1[i]-1][0]=arr2[i]
	t=1
	for i in range(n):
		if arr3[i][1]:
			continue
		k=arr3[i][0]-1
		arr3[i][1]=True
		while k!=i:
			arr3[k][1]=True
			k=arr3[k][0]-1
		t*=2
		t%=1000000007

	print(t)

