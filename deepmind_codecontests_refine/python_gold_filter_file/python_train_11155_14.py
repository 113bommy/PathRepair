n = int(input())

arr = list(map(int,input().split(" ")))

c = 0

for i in range(n-1):

	if((arr[i]==2 and arr[i+1]==1) or (arr[i]==1 and arr[i+1] == 2)):
		c += 3


	elif((arr[i]==3 and arr[i+1]==1) or (arr[i]==1 and arr[i+1] == 3)):
		c += 4


	else:
		print("Infinite")
		exit()


	if(i>0 and (arr[i-1]==3 and arr[i+1]==2)):
		c -= 1


print("Finite")
print(c)

