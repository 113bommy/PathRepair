def solve():
	INF = 10000000
	N, K = map(int, input().split())
	pos = input()
	leftDist = [0] * N
	rightDist = [0] * N
	ans = 0
	i = N - 1
	while i >= 0:
		if i == N - 1:
			rightDist[i] = 0 if pos[i] == '1' else INF
		else:
			rightDist[i] = 0 if pos[i] == '1' else rightDist[i + 1] + 1
		i -= 1
	# print(rightDist)
	for i in range(N):
		if i == 0:
			leftDist[i] = 0 if pos[i] == '1' else INF
		else:
			leftDist[i] = 0 if pos[i] == '1' else leftDist[i - 1] + 1
		if leftDist[i] > K and rightDist[i] > K:
			ans += 1
			leftDist[i] = 0
			rightDist[i] = 0
	return ans
	


def main():
	for _ in range(int(input())):
		print(solve())


if __name__ == '__main__':
	main()