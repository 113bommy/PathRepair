for _ in range(int(input())):
	a, b = list(map(int, input().split()))
	ans = abs(b-a)//10
	if (b-a)%10 != 0:
		ans += 1
	print(ans)