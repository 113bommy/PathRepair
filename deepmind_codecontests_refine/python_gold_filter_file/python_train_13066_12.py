def solve(n, k, a):
	l, r, cur, answer_l, answer_r = 0, 0, 1, 0, 0

	cnt = [0 for _ in range(1000010)]
	cnt[a[0]] = 1

	while r + 1 < n:
		r += 1
		cnt[a[r]] += 1

		if cnt[a[r]] == 1:
			cur += 1

		if cur > k:
			if r - l - 1 > answer_r - answer_l:
				answer_l, answer_r = l, r - 1

		while cur > k:
			cnt[a[l]] -= 1
			
			if cnt[a[l]] == 0:
				cur -= 1

			l += 1

	if r - l > answer_r - answer_l:
		answer_l, answer_r = l, r

	print(answer_l + 1, answer_r + 1)


if __name__ == '__main__':
	n, k = map(int, input().split())

	a = list(map(int, input().split()))

	solve(n, k, a)
