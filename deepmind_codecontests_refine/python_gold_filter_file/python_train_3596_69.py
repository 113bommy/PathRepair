n,ice = map(int,input().split())
kid = 0
arr = []
for i in range(n):
	x,y = map(str,input().split())
	arr.append((x,y))

for i in range(n):
	if(arr[i][0] == '+'):
		ice += int(arr[i][1])
	else:
		ice -= int(arr[i][1])
		if(ice < 0):
			kid += 1
			ice += int(arr[i][1])

print(ice,end=" ")
print(kid)