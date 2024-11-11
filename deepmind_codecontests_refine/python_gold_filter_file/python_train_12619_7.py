"""609C"""
# import math
# import sys
def  main():
	n ,q = map(int,input().split())
	floor = [[0 for j in range(n)] for i in range(2)]
	blocked = 0
	for _ in range(q):
		x,y = map(lambda n :int(n)-1,input().split())
		if floor[x][y] == 0:
			delta = 1
		else:
			delta = -1

		floor[x][y] = 1 - floor[x][y]
		for i in range(-1,2):
			if y+i>=0 and y+i<n and floor[1-x][y+i]==1:
				blocked += delta
		if blocked:
			print("NO")
		else:
			print("YES")
	return

main()
# def test():
# 	t = int(input())
# 	while t:
# 		main()
# 		t-=1
# test()
