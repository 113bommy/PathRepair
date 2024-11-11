if __name__ == '__main__':
	for _ in range (int(input())):
		a,b,c = map(int, input().split())
		ans = a+b+c-1
		print(ans)