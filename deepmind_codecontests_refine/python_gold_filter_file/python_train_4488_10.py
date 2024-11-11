temp = list(map(int, input().rstrip().split(" ")))
n = temp[0]
k = temp[1]
s = input()
s = list(s)
low = n
t = set(s)
t = list(t)
for i in range(len(t)):
	c = s.count(t[i])
	if c<low:
		low = c
f = 0
for i in range(k):
	if(s.count(chr(65+i)))<low:
		f = 1
if f==1:
	print(0)
else:
	print(k*low)