import sys
n =  int(input())
s = input()
t = input()
l1 = []
l2 = []
for i in range(n):
	if s[i] == 'a' and t[i] == 'b':
		l1.append(i+1)
	if s[i] == 'b' and t[i] == 'a':
		l2.append(i+1)
if (len(l1)+len(l2))%2 != 0:
	print(-1)
	sys.exit()
if len(l1)%2 != 0:
	ans = int(len(l1)/2)+int(len(l2)/2)+2
	print(ans)
	for i in range(1,len(l1)-1,2):
		print(l1[i-1],l1[i])
	for i in range(2,len(l2),2):
		print(l2[i-1],l2[i])
	print(l1[len(l1)-1],l1[len(l1)-1])
	print(l1[len(l1)-1],l2[0])
else:
	ans = int(len(l1)/2)+int(len(l2)/2)
	print(ans)
	for i in range(1,len(l1),2):
		print(l1[i-1],l1[i])
	for i in range(1,len(l2),2):
		print(l2[i-1],l2[i])