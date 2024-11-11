n,k=map(int,input().split())
l=list(map(int,input().split()))
ki = 1
p0 = 0
i = 0
s = 0

for j in range(n):
	if l[j] == 0 :
		s+= 1
	while s > k :
		if l[i] == 0 :
			s -= 1
		i += 1

	if j-i > p0- ki :
		p0 = j
		ki = i

print(p0-ki+1)
for h in range(ki,p0+1) :
	l[h] = 1
print(*l, sep= ' ')







		




		



	 





