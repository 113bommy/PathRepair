import sys
import functools
# sys.setrecursionlimit(1000000)
n, q = [int(x) for x in sys.stdin.readline().strip().split()]
arr = [int(x) for x in sys.stdin.readline().strip().split()]
query = []
p = [0]*(n+2)
for i in range(q):
	l,r=[int(x) for x in sys.stdin.readline().strip().split()]
	query.append([l,r])
	p[l]+=1
	p[r+1]-=1
for i in range(1,n+2):
	p[i]+=p[i-1]
p = p[:-1]
arr = [0]+arr
s_index = list(range(n+1))
s = sorted(s_index,key = lambda x: p[x]*10**6+x)
arr = sorted(arr)
new_arr = [0]*(n+1)
for i,j in enumerate(s):
	new_arr[j] = arr[i]
for i in range(1,n+1):
	new_arr[i]+=new_arr[i-1]
s = 0
for i,j in query:
	s+=new_arr[j]-new_arr[i-1]
print(s)

