n = int(input())
a = []
for i in range(n):
	a.append(input().split(' '))
	
valid = [1] * n
res = 0
for x in range(2000, -1, -1):
	pos_sell = -1
	pos_win = -1
	for i in range(n):
		if valid[i] == 0: continue
		if a[i][0] == 'sell' and int(a[i][1]) == x:
			pos_sell = i
			break
	for i in range(n):
		if valid[i] == 0: continue
		if i > pos_sell: break
		if a[i][0] == 'win' and int(a[i][1]) == x:
			pos_win = i
	if pos_sell == -1 or pos_win == -1:
		continue
	fun = 1
	for i in range(pos_win, pos_sell+1):
		if valid[i] == 0:
			fun = 0
			break
	if fun == 0:
		continue
	for i in range(pos_win, pos_sell+1):
		valid[i] = 0
	res += pow(2, x)
 
print(res)