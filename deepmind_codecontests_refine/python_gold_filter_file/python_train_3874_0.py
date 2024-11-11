for _ in range(int(input())):

	l = [int(i)for i in input().split()]

	ds = 0 
	# print("Input: ",l)
	while sum(l)>1 and l.count(0)<2:

		mx = max(l)

		if l.count(mx)==1:
			mx2 = sum(l)-mx-min(l)
			dx = mx2-min(l)
			if dx==0:
				mx2 = min(l)
				dx = min(mx-mx2,mx2)

			l[l.index(mx)]-=dx
			l[l.index(mx2)]-=dx
			ds+=dx
		elif l.count(mx)==2:
			dx = mx-min(l)
			l[l.index(mx)]-=dx
			l[l.index(mx)]-=dx
			ds+=dx
		else:
			if l[0]==1:
				ds+=1
				break
			dx = l[0]//2
			l[0]-=2*dx
			l[1]-=1*dx
			l[2]-=1*dx
			ds+=dx*2
		# print(l,mx,ds)
	print(ds)

