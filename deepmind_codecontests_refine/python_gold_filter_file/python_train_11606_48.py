max_val = 1
fact = 1
n = int(input())
for j in range(0,n-1):
	fact*=(j+1)
	max_val*=((2*n)-j-2)
max_val//=fact
print(max_val)