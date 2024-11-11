t = int(input())
for i in range(t):
	n = int(input())
	arr = list(map(int, input().split(' ')))
	pos = n-1
	while pos>0 and arr[pos-1]>=arr[pos]:
		pos-=1
	while pos>0 and arr[pos-1]<=arr[pos]:
		pos-=1
	print(pos)