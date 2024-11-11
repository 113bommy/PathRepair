'''input
3
'''
done = False
b = int(input())
for i in range(1,b+1):
	if (done):
		break
	for j in range(1,i+1):
		if (i%j==0 and (i*j>b) and (i/j<b)):
			print(i,j)
			done = True
			break
if (done==False):
	print(-1)
