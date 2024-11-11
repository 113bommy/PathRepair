t = int(input())
for i in range(t) :
	n = int(input())
	work = list(map(int, input().split(" ")))
	h = 1
	d = False
	for j in range(n) :
		if (work[j] == 0) :
			if (j>=1) :
				if(work[j-1] == 0) :
					d = True
					break
		else :	
			if (j>=1) :
				if(work[j-1] == 1) :
					h += 5
				else :
					h += 1
			else :
				h += 1
	if (d is False) :
		print(h)
	else :
		print(-1)
