'''input
1
removeMin
'''
# I am Mr.Inconsistent 
from sys import stdin
import heapq



def process_input(iarr):
	oarr = []
	myheap = []
	heapq.heapify(myheap)
	
	for i in range(len(iarr)):
		if iarr[i][0] == 1:
			heapq.heappush(myheap, iarr[i][1])
			oarr.append(iarr[i])
	
		elif iarr[i][0] == 2:
			if len(myheap) == 0 or myheap[0] > iarr[i][1]:
				heapq.heappush(myheap, iarr[i][1])
				oarr.append([1, iarr[i][1]])
				oarr.append(iarr[i])
			elif myheap[0] < iarr[i][1]:
				while len(myheap) > 0 and myheap[0] < iarr[i][1]:
					heapq.heappop(myheap)
					oarr.append([3, -1])
				if len(myheap) == 0 or myheap[0] > iarr[i][1]:
					heapq.heappush(myheap, iarr[i][1])
					oarr.append([1, iarr[i][1]])
				oarr.append(iarr[i])
			
			else:
				oarr.append(iarr[i])
				continue
			
		else:
			if len(myheap) == 0:
				heapq.heappush(myheap, 1)
				oarr.append([1, 1])
			heapq.heappop(myheap)
			oarr.append(iarr[i])
	return oarr

# main starts
n = int(stdin.readline().strip())
iarr = []
for _ in range(n):
	inp = list(stdin.readline().split())
	if len(inp) == 2:
		inp[1] = int(inp[1])
		if inp[0] == 'insert':
			iarr.append([1, inp[1]])
		else:
			iarr.append([2, inp[1]])
	else:
		iarr.append([3, - 1])
oarr = process_input(iarr)
print(len(oarr))
for i in range(len(oarr)):
	if oarr[i][0] == 1:
		print('insert', oarr[i][1])
	elif oarr[i][0] == 2:
		print('getMin', oarr[i][1])
	else:
		print('removeMin')

