from itertools import accumulate

def solve():
	n, X, *x = map(int, open(0).read().split())
	acc = [0] + list(accumulate(x))
	ans = 1 << 60
	for div in range(1, n + 1):
		cost = 0
		phase = 1
		i = n
		while i > 0 and cost < ans:
			cost += (acc[i] - acc[max(i - div, 0)]) * max(5, 2 * phase + 1)
			i -= div
			phase += 1
		cost += (div + n) * X
		if cost < ans:
			ans = cost
	print(ans)

if __name__ == "__main__":
	solve()