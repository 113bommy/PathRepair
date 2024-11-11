n=int(input())
l=[int(input()) for _ in range(n)]
k=sorted(l)

for i in l:
	if i<k[-1]:
		print(k[-1])
	if i==k[-1]:
		print(k[-2])
