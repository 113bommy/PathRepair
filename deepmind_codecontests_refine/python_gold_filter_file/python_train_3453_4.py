from collections import Counter
n = int(input())
a = sorted(list(map(int,input().split())))
c = Counter(a)
count = 0
for i in c:
	if c[i]>=2:
		count += (c[i]-1)
		num = i
if count>1:
	print ("cslnb")
	exit()
b = [i for i in range(n)]
if count==0 or (count==1 and num-1 not in c and num!=0):
	diff = 0
	for i in range(n):
		diff += a[i]-b[i]
	if diff%2:
		print ("sjfnb")
	else:
		print ("cslnb")
else:
	print ("cslnb")


