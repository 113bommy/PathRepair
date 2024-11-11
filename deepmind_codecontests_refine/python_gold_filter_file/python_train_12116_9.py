# your code goes here
import sys
l, r = tuple(int(x) for x in sys.stdin.readline().split())
l = bin(l)
r = bin(r)
l = l[2:]
r = r[2:]
l = l.zfill(len(r))
#print (l)
#print (r)
i = 0
while l[i] == r[i]:
	if i == len(l)-1:
		print (0)
		sys.exit()
	i+=1
i=len(l)-i
print(2**i-1)		