
f=lambda: map(int, input().split(' '))
v, e =f()
if e==0:
	print(v,v)
else:
	mini = v-(e*2)
	if mini<0:
		mini = 0
	low = 0
	high = v
	a = []
	while(low<high):
		mid = (low+high)//2
		if mid in a:
			maxi = v-high
			break
		else:
			a.append(mid)
		if (mid*(mid-1))//2 == e:
			maxi = v-mid
			break
		elif (mid*(mid-1))//2 > e:
			high = mid
		else:
			low = mid
	print(mini,maxi)