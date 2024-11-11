'''input
7
34 34 68 34 34 68 34
'''
# I am Mr.Inconsistent 
from sys import stdin
import math


# main starts
n = int(stdin.readline().strip())
arr = list(map(int, stdin.readline().split()))
for i in range(len(arr)):
	while arr[i] % 2 == 0 :
			arr[i] //= 2
	while arr[i] % 3 == 0 :
			arr[i] //= 3
c = arr[0]
#print(arr)
for i in range(1, len(arr)):
	if arr[i] != c:
		print("No")
		break
else:
	print("Yes")