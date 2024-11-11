x = int(input())

for _ in range(x):
	total = 0
	c,v=[*map(int, input().split())]
	if (c%2==0) and (v%2==0):
		print((c+v)//2)
	elif (c%2!=0) and (v%2!=0):
		print(-1*(c+v)//2)
	elif (c%2==0) and (v%2!=0):
		print(((c+(v-1))//2)-v)
	elif (c%2!=0) and (v%2==0):
		print((((c+(v-1))//2)-v)*(-1))
