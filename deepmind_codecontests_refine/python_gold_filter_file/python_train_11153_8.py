n = eval(input())
lamps = input()

permutations = ['RGB', 'RBG', 'BGR', 'BRG', 'GRB', 'GBR']

minimum = n
pattern = ''
for i in permutations:
	count = 0
	for j in range(len(lamps)):
		if(j%3==0 and lamps[j]!=i[0]):
			count+=1
		elif(j%3==1 and lamps[j]!=i[1]):
			count+=1
		elif(j%3==2 and lamps[j]!=i[2]):
			count+=1
	if(count<minimum):
		pattern = i
		minimum = count

answer = ''
for i in range(n):
	answer+=pattern[i%3]
print(minimum)
print(answer)