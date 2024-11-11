import math
n = int(input())
string = input()
f=0
for i in range(math.ceil(n/2)+1):
	if string[:i]==string[i:(i+len(string[:i]))]:
		f = len(string[:i])
if f!=0:
	print(n-f+1)
else:
	print(n)