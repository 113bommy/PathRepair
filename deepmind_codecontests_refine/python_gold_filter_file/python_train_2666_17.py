n=int(input())
s=0
max=0
l=[j for j in input().split(' ')]
for i in l:
	l1=list(i)
	s=0
	for k in l1:
		if k>='A' and k<='Z':
			s=s+1
	if s>max:
		max=s
print(max)