n=int(input())
l=list(map(int,input().split()))
l.sort(reverse=True)
s=0
for x in range(n):
	s+=l.pop(0)
	if s>sum(l):
		print(x+1)
		break
else:
	print(n)