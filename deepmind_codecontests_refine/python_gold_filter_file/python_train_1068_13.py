#: Author - Soumya Saurav
import sys,io,os,time
from collections import defaultdict
from collections import Counter
from collections import deque
from itertools import combinations
from itertools import permutations
import bisect,math,heapq
alphabet = "abcdefghijklmnopqrstuvwxyz"

input = sys.stdin.readline

########################################
for ii in range(int(input())):
	n , k = map(int , input().split())
	arr = list(map(int , input().split()))
	if k == len(set(arr)):
		print(1)
	else:
		ans = 0
		f = 0
		#print("here")
		for _ in range(1000):
			#print("!!",arr)
			if len(set(arr)) == 1:
				f = 1
				break
			c = 0
			have = defaultdict(int)
			for i in range(n):
				if arr[i] in have:
					arr[i] = 0
					continue
				else:
					if c < k: 
						c += 1
						have[arr[i]] = 1
						arr[i] = 0
			#print("c , have : ",c,have)
			ans += 1
		if f:
			print(max(1,ans))
		else:
			print(-1)
				
					
		

'''
11 3
0 1 2 2 3 3 3 4 4 4 4
'''






'''
# Wrap solution for more recursion depth
#submit as python3
import collections,sys,threading
sys.setrecursionlimit(10**9)
threading.stack_size(10**8)



threading.Thread(target=solve).start()
'''
