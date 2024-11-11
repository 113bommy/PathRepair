n = int(input())

names = []
scores = []
history = []

for i in range(n):
	q = input().split()
	
	name = q[0]
	score = int(q[1])
	
	if name in names:
		iname = names.index(name) 
		scores[iname] += score
	
	else:
		names.append(name)
		scores.append(score)

	iname = names.index(name)
	score = scores[iname]
	history.append([name, score])
	
mscore = max(scores)

cname = scores.count(mscore)
if cname == 1:
	iname = scores.index(mscore)
	print(names[iname])

else:
	nameswin = []
	for i in range(len(scores)):
		if scores[i] == mscore:
			nameswin += [names[i]]

	for h in history:
		if h[0] in nameswin:
			if h[1] >= mscore:
				print(h[0])
				break