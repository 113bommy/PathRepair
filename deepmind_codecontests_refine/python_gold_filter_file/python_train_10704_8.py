N = int(input())
S = str(input())

count = S.count('E')

if S[0] == 'E':
	count-=1

countmin = count

for i in range (1, N):
	if S[i] == 'E':
		count-=1
	if S[i-1] == 'W':
		count+=1
	if count < countmin:
		countmin = count

print(countmin) 