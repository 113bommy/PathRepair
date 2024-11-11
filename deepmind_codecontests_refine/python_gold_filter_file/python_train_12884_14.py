import math
getInputList = lambda : list(input().split())
getInputIntList = lambda : list(map(int,input().split()))


n = int(input())
arr = getInputIntList()
myset = set(arr)
if 0 in myset:
	print(len(myset)-1)
else:
	print(len(myset))