a = int(input())


b = input().split()

p = b[-1]
for i in range(len(b)-1,-1,-1):

	if(p != b[i]):
		break

print(i+1)