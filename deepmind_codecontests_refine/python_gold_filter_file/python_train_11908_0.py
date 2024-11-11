n = int(input())
li = [int(x) for x in input().split()]
monD = []
ans = 0	
for i, j in zip( li, range( 0, len(li) ) ):
	if j == 0:
		monD.append(i)
	else:
		#print(monD, "adsd", monD[-1])
		fl = 1
		if monD[-1] > i:
			ans = max(ans, i ^ monD[-1])
			monD.append(i)
		else:
			while monD[-1] < i:
				ans = max(ans, i ^ monD[-1])
				_ = monD.pop()
				if len(monD) == 0:
					fl = 0
					break
			if fl != 0:
				ans = max(ans, i ^ monD[-1])
			monD.append(i)
print(ans)
