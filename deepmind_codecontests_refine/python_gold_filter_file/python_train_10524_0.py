n = int(input())
table = []
l = map(int,input().split())
sonMark = sum(l)
table.append(sonMark)
for i in range(n-1):
	l = []
	l = map(int,input().split())

	table.append(sum(l))
table.sort()
table = table[::-1]


for i in range(len(table)):
	if sonMark == table[i]:
		print(i+1)
		break

