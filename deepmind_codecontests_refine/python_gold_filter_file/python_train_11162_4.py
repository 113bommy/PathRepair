from sys import exit
n = int(input())
arr = []
for _ in range(n):
	arr.append(tuple(map(int, input().split())))

def no():
	print("no")
	exit(0)

def yes():
	print("yes")
	exit(0)

if len(arr) & 1 == 1:
	no()

def center(a, b):
	return ((a[0] + b[0])/2, (a[1] + b[1])/2)

c = center(arr[0], arr[len(arr)//2])
for i in range(1, len(arr)//2):
	if c != center(arr[i], arr[i+len(arr)//2]):
		no()

yes()
