import re
import math

N_tests = int(input())
for test_case in range(N_tests):
	Data = list(map(int, input().split(' ')))
	cost = 0
	for n in range(Data[0]):
		m = str(input())
		x = re.findall('\.+', m)
		for W_tiles in x:
			Num = W_tiles.count('.')
			if (2*Data[2]) > Data[3]:
				Tile_2 = math.floor(Num/2)
				Tile_1 = (Num%2)
				cost = cost + (Tile_2*Data[3]) + (Tile_1*Data[2])
			else:
				cost = cost + (Num*Data[2])
	print(cost)
