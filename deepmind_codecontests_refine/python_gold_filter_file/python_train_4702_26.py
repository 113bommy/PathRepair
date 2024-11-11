n = int(input())
temp = []
stack = [1]
for i in range(n):
	op = input()
	xy = op.split("for ")

	if len(xy)==2:
		xy[0] = "for"
		xy[1] = int(xy[1])

	temp.append(xy)


i = 0
add = 0
flag = 0
n = len(temp)
inf = pow(2,32)


while(i<n):
	
	if temp[i][0] == "for":
			stack.append(min(inf, temp[i][1]*stack[-1]))
			i += 1
		

	elif temp[i][0] == "add":
		add = add+stack[-1]
		i += 1
		
		
	elif temp[i][0] == "end":
		stack.pop(-1)
		i += 1

if add < inf:
	print(add)
else:
	print("OVERFLOW!!!")
