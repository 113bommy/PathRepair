p,y = map(int,input().split())

for x in range(y,p,-1):
	# print(x)
	# check
	flag = True
	for i in range(2,min(p,int(x**0.5))+1):
		if x%i == 0:
			flag = False
			break
	if flag:
		print(x)
		exit()

print(-1)