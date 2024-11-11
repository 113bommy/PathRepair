t = int(input())

def check(a, j):

	for i in range(n-1,j,-1):
		if arr[i] > a:
			return [True,i]

	return [False, -1]

while t:

	n = int(input())
	arr = list(map(int, input().split()))
	if arr[0] + arr[1] <= arr[n-1]:
		print(1, 2, n)
	else:
		print("-1")

	t-=1