 
# from math import factorial as fac
from collections import defaultdict
# from copy import deepcopy
import sys, math
f = None
try:
	f = open('q1.input', 'r')
except IOError:
	f = sys.stdin
if 'xrange' in dir(__builtins__):
	range = xrange
# print(f.readline())
sys.setrecursionlimit(3*10**6)

	
def print_case_iterable(case_num, iterable):
	print("Case #{}: {}".format(case_num," ".join(map(str,iterable))))

def print_case_number(case_num, iterable):
	print("Case #{}: {}".format(case_num,iterable))

def print_iterable(A):
	print (' '.join(A))

def read_int():
	return int(f.readline().strip())
def read_int_array():
	return [int(x) for x in f.readline().strip().split(" ")]
def rns():
	a =  [x for x in f.readline().split(" ")]
	return int(a[0]), a[1].strip()
def read_string():
	return list(f.readline().strip())
def ri():
	return int(f.readline().strip())
def ria():
	return [int(x) for x in f.readline().strip().split(" ")]
def rns():
	a =  [x for x in f.readline().split(" ")]
	return int(a[0]), a[1].strip()
def rs():
	return list(f.readline().strip())
def bi(x):
	return bin(x)[2:]





from collections import deque
import math
NUMBER = 10**9 + 7
# NUMBER = 998244353
def factorial(n) : 
	M = NUMBER
	f = 1
  
	for i in range(1, n + 1):  
		f = (f * i) % M # Now f never can  
						# exceed 10^9+7  
	return f
def mult(a,b):
	return (a * b) % NUMBER

def minus(a , b):
	return (a - b) % NUMBER

def plus(a , b):
	return (a + b) % NUMBER

def egcd(a, b):
	if a == 0:
		return (b, 0, 1)
	else:
		g, y, x = egcd(b % a, a)
		return (g, x - (b // a) * y, y)

def modinv(a):
	m = NUMBER
	g, x, y = egcd(a, m)
	if g != 1:
		raise Exception('modular inverse does not exist')
	else:
		return x % m
def choose(n,k):
	if n < k:
		assert false
	return  mult(factorial(n), modinv(mult(factorial(k),factorial(n-k)))) % NUMBER
from collections import deque, defaultdict 
import heapq


from types import GeneratorType
def bootstrap(f, stack=[]):
	def wrappedfunc(*args, **kwargs):
		if stack:
			return f(*args, **kwargs)
		else:
			to = f(*args, **kwargs)
			while True:
				if type(to) is GeneratorType:
					stack.append(to)
					to = next(to)
				else:
					stack.pop()
					if not stack:
						break
					to = stack[-1].send(to)
			return to

	return wrappedfunc


def dfs(g, timeIn, timeOut,depths,parents): 
	# assign In-time to node u 
	cnt = 0
	# node, neig_i, parent, depth
	stack = [[1,0,0,0]]
	while stack:
		v,neig_i,parent,depth = stack[-1]
		parents[v] = parent
		depths[v] = depth
		# print (v)
		if neig_i == 0:
			timeIn[v] = cnt    
			cnt+=1
		while neig_i < len(g[v]):
			u = g[v][neig_i]
			if u == parent:
				neig_i+=1
				continue
			stack[-1][1] = neig_i + 1
			stack.append([u,0,v,depth+1])
			break
		if neig_i == len(g[v]):
			stack.pop()
			timeOut[v] = cnt
			cnt += 1
  
# def isAncestor(u: int, v: int, timeIn: list, timeOut: list) -> str: 
# 	return timeIn[u] <= timeIn[v] and timeOut[v] <= timeOut[u] 

cnt = 0
@bootstrap
def dfs(v,adj,timeIn, timeOut,depths,parents,parent=0,depth=0):
	global cnt
	parents[v] = parent
	depths[v] = depth
	timeIn[v] = cnt
	cnt+=1
	for u in adj[v]:
		if u == parent:
			continue
		yield dfs(u,adj,timeIn,timeOut,depths,parents,v,depth+1)
	timeOut[v] = cnt
	cnt+=1
	yield 

def gcd(a,b): 
	if a == 0: 
		return b 
	return gcd(b % a, a) 
  
# Function to return LCM of two numbers 
def lcm(a,b): 
	return (a*b) / gcd(a,b) 
def get_num_2_5(n):
	twos = 0
	fives = 0
	while n>0 and n%2 == 0:
		n//=2
		twos+=1
	while n>0 and n%5 == 0:
		n//=5
		fives+=1
	return (twos,fives)
def shift(a,i,num):
	for _ in range(num):
		a[i],a[i+1],a[i+2] = a[i+2],a[i],a[i+1]

def equal(x,y):
	return abs(x-y) <= 1e-9
# def leq(x,y):
# 	return x-y <= 1e-9
def getAngle(a, b, c):
	ang = math.degrees(math.atan2(c[1]-b[1], c[0]-b[0]) - math.atan2(a[1]-b[1], a[0]-b[0]))
	return ang + 360 if ang < 0 else ang
def getLength(a,b):
	return math.sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2)


from heapq import heapify, heappush, heappop

def bfs(adj):
	s = set()
	d = defaultdict(set)
	# print('\n'.join(map(str,E.items())))
	q = deque([])
	s.add(0)
	d[0].add(0)
	q.append((0,0))
	while len(q) > 0:
		v,depth = q.popleft()
		for u in adj[v]:
			if u not in s:
				s.add(u)
				d[depth+1].add(u)
				q.append((u,depth+1))
		# print(q)
	return d



def isSubsetSum(arr, n, summ): 
	  
	# The value of subarr[i][j] will be  
	# true if there is a 
	# subarr of arr[0..j-1] with summ equal to i 
	subarr =([[False for i in range(summ + 1)]  
			for i in range(n + 1)]) 
	  
	# If summ is 0, then answer is true  
	for i in range(n + 1): 
		subarr[i][0] = True
		  
	# If summ is not 0 and arr is empty,  
	# then answer is false  
	for i in range(1, summ + 1): 
		 subarr[0][i]= False
			  
	# Fill the subarr table in botton up manner 
	for i in range(1, n + 1): 
		for j in range(1, summ + 1): 
			if j<arr[i-1]: 
				subarr[i][j] = subarr[i-1][j] 
			if j>= arr[i-1]: 
				subarr[i][j] = (subarr[i-1][j] or 
								subarr[i - 1][j-arr[i-1]]) 
	  
	# uncomment this code to print table  
	# for i in range(n + 1): 
	# for j in range(summ + 1): 
	# print (subset[i][j], end =" ") 
	# print() 
	return subarr[n][summ] 



def bfs(v,adj,onpath):
	# d is a dict for depth
	s = set()
	d = defaultdict(set)
	q = deque([])
	s.add(0)
	d[0].add(0)
	q.append((0,0))
	while len(q) > 0:
		v,depth = q.popleft()
		for u in adj[v]:
			if u not in s:
				s.add(u)
				d[depth+1].add(u)
				q.append((u,depth+1))
		# print(q)
	return d

@bootstrap
def dfs(v,p,adj,b, path):
	if v == b:
		path.append(b)
		yield True
	for u in adj[v]:
		if u == p:
			continue
		on = yield dfs(u,v,adj,b,path)
		if on:
			path.append(v)
			yield True
	yield False

@bootstrap
def dfs1(v,p,adj,d,mcd,onpath,c,root):
	if len(mcd) < d+1:
		mcd.append([c[v],d,root,v])
	if mcd[d][0] > c[v]:
		mcd[d][0] = c[v]
		mcd[d][3] = v

	for u in adj[v]:
		if u == p or onpath[u]:
			continue
		yield dfs1(u,v,adj,d+1,mcd,onpath,c,root)
		
	yield False





def solution(n,k,l1,r1,l2,r2):
	if l2  < l1:
		l1,r1,l2,r2=l2,r2,l1,r1
	#assume r2 > r1
	if l2 > r1:
		cur_inter = 0 
	else:
		cur_inter = (min(r2,r1) - max(l1,l2))*n
	if cur_inter >= k:
		return 0
	if cur_inter > 0 or l2==r2 and r2<=r1:
		# print('yo')
		cnt = 0
		if (max(r2,r1)-l1) * n >= k:
			return k - cur_inter
		cur_inter = (max(r2,r1)-l1) * n
		cnt+=(max(r2,r1) - min(r1,r2) + l2-l1) * n 
		left = k - cur_inter
		return cnt + left*2
	if cur_inter == 0:
		cnt = 0
		left = k
		if (r2-l1) >= left:
			return k + (l2-r1)
		cnt+=r2-r1 + l2-l1
		# print(cnt)
		cur_inter += r2-l1
		# print(cur_inter)
		if k<= (r2-l1)*n:
			for i in range(n-1):
				left = k-cur_inter
				if cur_inter + (r2-l1) >= k:
					if left <= (l2-r1):
						return cnt+2*left
					return cnt+(k-cur_inter) + (l2-r1)
				cur_inter+= r2-l1
				cnt+=r2-r1 + l2-l1
		cur_inter = (r2-l1) * n
		cnt = n*(r2-r1) + n*(l2-l1)
		# print('yo',k,cnt,cur_inter,l2-r1)
		left = k-cur_inter
		return cnt+left*2

	# if (r2 - l1)*(n*n) >= k:




def main():
	T = 1
	T = ri()
	for i in range(T):
		# n = ri()
		n,k= ria()
		l1,r1 = ria()
		l2,r2 = ria()
		# if i == 644:
		# 	print(''.join(map(str,[n,333,k,333,l1,333,r1,333,l2,333,r2])))
		# a = ria()
		# a = ria()
		# s = rs()
		# b = rs()
		# n,k,l	= ria()
		# a = ria()
		# adj = [list() for _ in range(n)]
		# costs = [0] * n
		# p,c=ria();
		# costs[0] = c
		# for j in range(1,n):
		# 	p,c=ria();
		# 	costs[j] = c 
		# 	p-=1
		# 	adj[j].append(p)
		# 	adj[p].append(j)

		x = solution(n,k,l1,r1,l2,r2)

		# continue
		if 'xrange' not in dir(__builtins__):
			print(x) # print("Case #"+str(i+1)+':',x)
		else:
			print >>output,str(x)
	if 'xrange' in dir(__builtins__):
		print(output.getvalue())
		output.close()

if 'xrange' in dir(__builtins__):
	import cStringIO
	output = cStringIO.StringIO()
#example usage:
#    for l in res:
#       print >>output, str(len(l)) + ' ' +  ' '.join(l)

if __name__ == '__main__':
	main()