def solve():
	s,a,b,c = map(int, input().split())
	ans = s//c
	ans += (ans//a)*b
	return ans

for _ in range(int(input())):
	print(solve())