n,x,y=[int(x) for x in input().strip().split()]
def ceil(val):
	if int(val)==val:
		return int(val)
	else:
 		return int(val)+1
num = ceil(n*y/100)
count = max(0,num-x)
print(count)
