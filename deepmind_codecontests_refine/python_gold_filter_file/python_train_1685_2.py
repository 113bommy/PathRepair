test = int(input())

while test :
	n = int(input())
	arr = list(map(int,input().split()))

	res = 0
	mn = arr[-1]

	for i in range (n - 1, -1, -1):
		if arr[i] > mn :
			res += 1
		else :
			mn = arr[i]

	print (res)

	test -= 1



# for _ in[0]*int(input()):
#  input();m=1e7;r=0
#  for x in[*map(int,input().split())][::-1]:r+=x>m;m=min(m,x)
#  print(r)