n=int(input())
string=input()
for i in range(n-1):
	if string[i]>string[i+1]:
		print("YES")
		print(i+1,end=' ')
		print(i+2)
		exit()
else:
	print("NO")