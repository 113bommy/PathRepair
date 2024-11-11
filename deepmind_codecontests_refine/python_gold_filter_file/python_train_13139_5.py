# import sys
# file = open('test1')
# sys.stdin = file


def ii(): return int(input())


def ai(): return list(map(int, input().split()))


def mi(): return map(int, input().split())


t = 1
for _ in range(t):
	n, q = mi()
	lava = [[0 for i in range(n)] for j in range(2)]
	blocked_pairs = 0
	while q:
		q -= 1
		x, y = map(lambda s: int(s)-1, input().split())
		delta = +1 if lava[x][y] == 0 else -1
		lava[x][y] = 1 - lava[x][y]
		for i in range(-1, 2):
			if y+i >= 0 and y+i < n and lava[1-x][y+i] == 1:
				blocked_pairs += delta
		if blocked_pairs == 0: print("Yes")
		else: print("No")
