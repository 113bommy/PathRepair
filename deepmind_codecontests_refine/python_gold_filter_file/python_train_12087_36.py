x = int(input())
h = 0
a = list(map(int,input().strip().split()))
for i in range(0,x):
	if(a[i]==1):
		h += 1		
if(h>0):
	print('hard')
else:
	print('easy')