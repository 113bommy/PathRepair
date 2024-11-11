def check(i):
	tot=k
	while(tot%i==0):
		tot//=i
	if(tot%i==1):
		setl.add(i)
import math
k=int(input())
if(k==2):
	print(1)
	exit()
setl = set()
setl.add(k); setl.add(k-1)
for x in range(2,int(math.sqrt(k))+1):
	check(x)
	check(k//x)
print(len(setl))