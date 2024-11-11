# -*- coding:utf-8 -*-
import sys
def dfs(x, y, sym):
	tile[x][y] = "."
	for i in range(len(DX)):
		nx = x + DX[i]
		ny = y + DY[i]
		if (0<=nx and nx<N and 0<=ny and ny<M and tile[nx][ny] is sym):
			dfs(nx, ny, sym)

def solve():
	res = 0
	for i in range(N):
		for j in range(M):
			sym = tile[i][j]
			if tile[i][j] != ".":
				if tile[i][j] is sym:
					dfs(i, j, sym)
					res += 1
	print(res)

counter=0
DX = [-1,0,1,0]
DY = [0,-1,0,1]
sys.setrecursionlimit(10**7)
while True:
	line = input()
	if " " in line:
		nums = line.split(" ")
		N = int(nums[0])
		M = int(nums[1])
		tile = [[0 for i in range(M)] for j in range(N)]
	else:
		tile[counter-1] = list(line)
	if N is 0 and M is 0:
		break
	counter += 1
	if counter-1 is N:
		solve()
		counter = 0