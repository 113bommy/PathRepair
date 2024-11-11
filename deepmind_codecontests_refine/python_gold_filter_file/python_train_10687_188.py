no, n = map(int,input().split())
for i in range(n):
	if str(no)[-1] != '0':
		no-=1
	else:
		no = int(str(no)[:-1])
print(no)
