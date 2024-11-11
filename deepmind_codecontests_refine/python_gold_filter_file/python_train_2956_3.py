# import sys
# sys.stdin=open('F:\\C\\Script\\input.txt','r')
# sys.stdout=open('F:\\C\\Script\\output.txt','w')
# sys.stdout.flush()

# MOD = 1000000007
I = lambda : [int(i) for i in input().split()]

n , m = I()
l = []
temp = I()
l.append(temp[0]*temp[1])
for _ in range(1,n):
	k = I()
	l.append(l[_-1] + k[0]*k[1])
# print (l)
s = I()
j = 0
for i in s:
	if i < l[j]:
		print ( j + 1)
	else:
		while i > l[j]:
			j += 1
		print (j + 1)