def input_int():
    return int(input())

def input_list():
    return input().split(' ')

def input_list_int():
    return list(map(int, input_list()))
res = []
def solve(xy, s):
	x = int(xy[0])
	y = int(xy[1])
	if (x > 0 and y > 0):
		if(s.count('R') >= x and s.count('U') >= y):
			res.append('YES')
		else:
			res.append('NO')
	elif (x > 0 and y < 0):
		if(s.count('R') >= x and s.count('D') >= abs(y)):
			res.append('YES')
		else:
			res.append('NO')
	elif (x < 0 and y > 0):
		if(s.count('L') >= abs(x) and s.count('U') >= abs(y)):
			res.append('YES')
		else:
			res.append('NO')
	elif (x < 0 and y < 0):
		if(s.count('L') >= abs(x) and s.count('D') >= abs(y)):
			res.append('YES')
		else:
			res.append('NO')
	elif (x == 0 and y > 0):
		if(s.count('U') >= y):
			res.append('YES')
		else:
			res.append('NO')
	elif (x == 0 and y < 0):
		if(s.count('D') >= abs(y)):
			res.append('YES')
		else:
			res.append('NO')
	elif (x > 0 and y == 0):
		if(s.count('R') >= x):
			res.append('YES')
		else:
			res.append('NO')
	elif (x < 0 and y == 0):
		if(s.count('L') >= abs(x)):
			res.append('YES')
		else:
			res.append('NO')
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        coordinates = input_list_int()
        commands = input()
        solve(coordinates, commands)
    for i in res:
        print(i)