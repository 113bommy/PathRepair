numbers=[]
def swap(a, b):
	t = numbers[a]
	numbers[a]=numbers[b]
	numbers[b]=t
cases=int(input())
for case in range(cases):
	n,m=map(int, input().split())
	numbers=list(map(int, input().split()))
	oper=list(map(int, input().split()))
	oper.sort()
	oper.reverse()
	for i in range(n):
		for j in range(m):
			if numbers[oper[j] - 1] > numbers[oper[j]]:
				swap(oper[j] - 1, oper[j])
	if numbers == sorted(numbers):
		print("YES")
	else:
		print("NO")
	