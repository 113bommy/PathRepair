n = int(input())
s1 = input()
s2 = input()

l = []
l1 = []
for i in range(n):
	l.append(int(s1[i]))

for i in range(len(s2)):
	l1.append(int(s2[i]))
l1.sort()
l.sort()
c = 0
c1 = 0
i = 0
j = 0
while i < len(l) and j < len(l1):
	if l[i] < l1[j]:
		i = i + 1
		j = j + 1
		c = c + 1
	else:
		j = j + 1
i = 0 
j = 0
while i < len(l) and j < len(l1):
	if l[i] <= l1[j]:
		i = i + 1
		j = j + 1
	else: 
		j = j + 1
		# i = i + 1
		c1 = c1 + 1

print(c1,c)
