n = int(input())
data = {}
ans = 0
res = 0
pos = 0
ind = []
for i in range(n):
	tmp = sorted(list(map(int, input().split())))
	
	if min(tmp) > ans:
		ans = min(tmp)
		ind = [i, -1]

	t = (tmp[1], tmp[2])
	if t in data:
		third, _ = data[t]
		if min([third + tmp[0], tmp[1], tmp[2]]) > ans:
			ans = min([third + tmp[0], tmp[1], tmp[2]])
			ind = [i, data[t][1]]
		if third < tmp[0]:
			data[t] = (tmp[0], i)
	else:
		data[t] = (tmp[0], i)

if ind[1] == -1:
	print(1)
	print(ind[0] + 1)
else:
	print(2)
	print(ind[0] + 1, ind[1] + 1)
 
