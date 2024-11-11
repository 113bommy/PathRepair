from bisect import bisect
from collections import defaultdict
def main():
	n, k = map(int, input().split())
	*a, = map(int, input().split())
	idx = defaultdict(list)
	for i, x in enumerate(a):
		idx[x].append(i)
	m = (k * n).bit_length()
	dub = [[-1] * n for _ in range(m)]
	for i, x in enumerate(a):
		if i == idx[x][-1]:
			dub[0][i] = n + idx[x][0] - i
		else:
			dub[0][i] = idx[x][bisect(idx[x], i)] - i
	# print(dub[0])
	for i in range(m - 1):
		for j in range(n):
			if dub[i][j]<n*k and dub[i][j]!=-1:
				dub[i + 1][j] = dub[i][j] + 1 + dub[i][(j + dub[i][j] + 1) % n]
	# print(dub)
	now = -1
	for i in range(m - 1, -1, -1):
		if dub[i][(now+1)%n]!=-1 and now + 1 + dub[i][(now + 1) % n] < n * k:
			now += 1 + dub[i][(now + 1) % n]
	# print(now)
	if now == n * k:
		print("")
		exit()
	b = a[(now + 1) % n:]
	# print(b)
	inQ = {x: False for x in b}
	Q = []
	for x in b:
		if inQ[x]:
			while Q[-1] != x:
				inQ[Q.pop()] = False
			Q.pop()
			inQ[x] = False
		else:
			inQ[x] = True
			Q.append(x)
	print(" ".join(map(str, Q)))

if __name__ == '__main__':
	main()
