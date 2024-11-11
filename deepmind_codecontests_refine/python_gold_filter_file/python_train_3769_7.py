for _ in range(int(input())):
	a = int(input())
	b = list(map(int, input().split()))
	print((sum(b)+a-1)//a)
