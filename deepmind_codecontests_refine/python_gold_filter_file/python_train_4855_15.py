a=[1,6,28,120,496,2016,8128,32640]

b=int(input())

for i in range(0,8):

	if b%a[i]==0:
		c=a[i]

print(str(c))