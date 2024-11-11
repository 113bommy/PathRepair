n = int(input())
r = list(map(int,input().split()))

def resp(r):
	for i in r:
		if i == 1:
			return 'Hard'

	return 'Easy'

print(resp(r))