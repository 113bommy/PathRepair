
x=int(input())
for i in range(x):
	n=int(input())
	l=[int(x) for x in input().split()]
	l.sort()
	print(min(l[j+1]-l[j] for j in range(n-1)))