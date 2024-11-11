t=int(input())
for i in range(t):
	a = [int(ii) for ii in input().split()]
	s= sum(a)
	out = True
	for j in a:
		if j > (s+1)//2:
			out = False
	if out:
		print("Yes")
	else:
		print("No")
		