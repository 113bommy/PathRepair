'''input
4 3 9
'''
n, m, k = map(int, input().split())
if k % (2*m) == 0:
	l = k // (2*m)
else:
	l = k // (2*m) + 1
print(l, end = " ")
if (k+1)//2 % m == 0:
	print(m, end = " ")
else:
	print((k+1)//2 % m, end = " ")
print("L" if k % 2 == 1 else "R")