l = input()
l = l.split()
n = int(l[0])
m = int(l[1])
array = []
s = ""
for i in range(0,m+2):
	s = s+"0"
array.append(s)
# print(array[0])
for i in range(0, n):
	x = input()
	x = "0"+x+"0"
	array.append(x)
array.append(s)
flag = 0
for i in range(1, n+1):
	for j in range(1,m+1):
		if(array[i][j] != "*"):
			val = 0
			if(array[i][j] == "."):
				val = 0
			else:
				val = int(array[i][j])
			cnt = 0
			for k in range(i-1,i+2):
				for l in range(j-1,j+2):
					# print(array[k][l])
					if(array[k][l] == "*"):
						cnt = cnt+1

			if(cnt != val):
				print("NO")
				# print(val)
				# print(j)
				flag = 1
				break
	if(flag == 1):
		break
# print("YES")
if(flag == 0):
	print("YES")
# print(n)
# print(array[2])