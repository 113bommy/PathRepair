t = int(input())
import math
for z in range(t):
	n, x, y, d = list(map(int, input().split()))
	temp = abs(y - x)
	
	if(temp % d == 0):
		print(temp//d)
		continue

	else:
		left = math.ceil((x - 1)/d)
		right = math.ceil((n - x)/d)
		dl = -1
		dr = -1
		if((y - 1)%d == 0):
			dl = (y - 1)//d
		if((n - y)%d == 0):
			dr = (n - y)//d

		#print(left, right, dl, dr)
		if(dl == -1 and dr == -1):
			print(-1)
		elif(dl == -1 and dr != -1):
			print(right + dr)
		elif(dr == -1 and dl != -1):
			print(left + dl)
		else:
			print(min(left + dl, right + dr))
