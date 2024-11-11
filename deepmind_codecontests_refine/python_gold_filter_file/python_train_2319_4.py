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
	n = int(input())
	arr = list(map(int , input().split()))
	count = Counter(arr)
	if len(count) == n:
		arr.sort()
		ans = [-1]*n
		j = (n + 1)//2 - 1
		for i in range(n//2,n):
			ans[i] = arr[j]
			j-=1
		print(*ans)
		continue
	if len(count) == 1:
		print(*arr)
		continue
	ind = defaultdict(list)
	for i in range(n):
		ind[arr[i]].append(i+1)
	ind = sorted(ind.items(), key = lambda x : (-len(x[1]), x[0]))
	#print(ind)
	ans = [-1]*n
	mapka = {i:float("inf") for i in range(1,n+1)}
	for k, v in ind:
		maxgap = max(v[0], n - v[-1] + 1)
		for i in range(len(v)-1):
			maxgap = max(maxgap, v[i+1] - v[i])
		mapka[maxgap] = min(k,mapka[maxgap])
		#print("!!!", k , maxgap)
	#print("mapka",mapka)
	prev = float("inf")
	for k, v in mapka.items():
		if v!= float("inf"):
			prev = min(prev , v)
			ans[k-1] = prev
		else:
			if prev == float("inf"): ans[k-1] = -1
			else: ans[k-1] = prev
	ans[n-1] = min(arr)
	print(*ans)



'''
2
5
1 3 3 2 2
6
1 1 1 1 3 3

'''





'''
# Wrap solution for more recursion depth
#submit as python3
import collections,sys,threading
sys.setrecursionlimit(10**9)
threading.stack_size(10**8)



threading.Thread(target=solve).start()
'''
