'''input
4
2
-1 -2 0 0 0 0
-1 -2 0 0 0 0
3
1 5 1 1 1 1
2 5 0 1 0 1
3 5 1 0 0 0
2
1337 1337 0 1 1 1
1336 1337 1 1 0 1
1
3 5 1 1 1 1
'''
from copy import deepcopy
from bisect import bisect_right
from itertools import combinations
from sys import stdin


def left():
	return 1 +1

def right():
	return 1 +3

def down():
	return 1 + 2

def up():
	return 1 + 4 


def reachable(point, robot, t):
	if t == 1:
		for i in range(len(robot)):
			if robot[i][0] == point or (robot[i][0] > point and robot[i][left()] == 1):
				pass
			else:
				return False
		else:
			return True

	elif t == 2:
		for i in range(len(robot)):
			if robot[i][1] == point or (robot[i][1] < point and robot[i][down()] == 1):
				pass
			else:
				return False
		else:
			return True

	elif t == 3:
		for i in range(len(robot)):
			if robot[i][0] == point or (robot[i][0] > point and robot[i][right()] == 1):
				pass
			else:
				return False
		else:
			return True


	else:
		for i in range(len(robot)):
			if robot[i][1] == point or (robot[i][1] > point and robot[i][up()] == 1):
				pass
			else:
				return False
		else:
			return True


# main starts
q = int(stdin.readline().strip())
for _ in range(q):
	n = int(stdin.readline().strip())
	robot = []
	for _ in range(n):
		robot.append(list(map(int, stdin.readline().split())))

	xl = -10 ** 5
	xr =  10 ** 5
	yt = 10 ** 5
	yb = -10 ** 5

	flag = True

	for i in range(n - 1):
		if robot[i][0] != robot[i + 1][0] or robot[i][1] != robot[i + 1][1]:
			flag = False
			break

	if flag == True:
		print(1, robot[0][0], robot[0][1])
		continue

	for i in range(n):
		if robot[i][2] == 0:
			if xl < robot[i][0]:
				xl = robot[i][0]

		if robot[i][4] == 0:
			if xr > robot[i][0]:
				xr = robot[i][0]

		if robot[i][3] == 0:
			if yt > robot[i][1]:
				yt = robot[i][1]

		if robot[i][5] == 0:
			if yb < robot[i][1]:
				yb = robot[i][1]
	if xl > xr or yt < yb:
		print(0)
		continue
	else:
		print(1, (xl + xr) // 2, (yt + yb) // 2)