n = int(input())

son = 0
rank = 0
s = 100000

for i in range(n):
	a = list(map(int, input().split()))

	if(i==0):
		son = sum(a)
	else:
		s = sum(a)
	
	if s>son:
		rank+=1

print(rank)