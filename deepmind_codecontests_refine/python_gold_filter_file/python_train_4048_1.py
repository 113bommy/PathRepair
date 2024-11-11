import sys
import math

def decide_move(x,y,tile,check):
	if tile == '<':
		y -= 1
		check[x][y] += 1
		return x,y,check
	elif tile == '>':
		y += 1
		check[x][y] += 1
		return x,y,check
	elif tile == '^':
		x -= 1
		check[x][y] += 1
		return x,y,check
	else:
		x += 1
		check[x][y] += 1
		return x,y,check


while True:
	h,w = map(int,input().split())
	if h == 0:
		break
	tile_map = []
	for i in range(h):
		tile_map.append(input())
	check =[[0 for i in range(w)]for j in range(h)]
	check[0][0] = 1
	x = 0
	y = 0
	status = 0

	while True:
		if tile_map[x][y] == '.':
			status = 1
			print(y,x)
			break
		x,y,check = decide_move(x,y,tile_map[x][y],check)
		if check[x][y] > 1:
			status = 1
			print('LOOP')
			break