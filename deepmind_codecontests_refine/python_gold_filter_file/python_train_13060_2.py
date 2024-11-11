import math

N = int(input())
prime = []
numberlist = []
for i in range(2, int(math.sqrt(N))+1):
	numberlist.append(i)
while numberlist[0] <= int(math.sqrt(math.sqrt(N))):
	now = numberlist.pop(0)
	prime.append(now)
	newnumberlist = []
	while numberlist != []:
		next = numberlist.pop(0)
		if next%now != 0:
			newnumberlist.append(next)
	numberlist = newnumberlist
prime = prime + numberlist

for i in range(2, N+1):
	flag1 = False
	flag2 = False
	for j in range(0, len(prime)):
		if i%prime[j] == 0 and i//prime[j] != 1:
			flag1 = True
			break
	for j in range(0, len(prime)):
		if (N-i)%prime[j] == 0 and (N-i)//prime[j] != 1:
			flag2 = True
			break
	if flag1 and flag2:
		print(str(i) + ' ' + str(N-i))
		break