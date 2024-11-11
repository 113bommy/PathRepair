######################################################
############Created by Devesh Kumar###################
#############devesh1102@gmail.com####################
##########For CodeForces(Devesh1102)#################
#####################2020#############################
######################################################
import sys
input = sys.stdin.readline

# import sys
import heapq 
import copy
import math
import decimal
# import sys.stdout.flush as flush
# from decimal import *
#heapq.heapify(li) 
#
#heapq.heappush(li,4) 
#
#heapq.heappop(li)
#
# &	Bitwise AND Operator	10 & 7 = 2
# |	Bitwise OR Operator	10 | 7 = 15
# ^	Bitwise XOR Operator	10 ^ 7 = 13
 
# <<	Bitwise Left Shift operator	10<<2 = 40
# >>	Bitwise Right Shift Operator
# '''############ ---- Input Functions ---- #######Start#####'''
 
 
class Node:
    def _init_(self,val):
        self.data = val
        self.left = None
        self.right = None
##to initialize wire : object_name= node(val)##to create a new node
## can also be used to create linked list
 
 
def pre_sum(arr):
	#"""returns the prefix sum inclusive ie ith position in ans  represent sum from 0 to ith position"""
	p = [0]
	for i in arr:
		p.append(p[-1] + i)
	p.pop(0)
	return p
 
def pre_back(arr):
	#"""returns the prefix sum inclusive ie ith position in ans  represent sum from 0 to ith position"""
	p = [0]
	for i in arr:
		p.append(p[-1] + i)
	p.pop(0)
	return p
def bin_search(arr,l,r,val):#strickly greater
	if arr[r] <= val:
		return r+1	
	if r-l < 2:
		if arr[l]>val:
			return l
		else:
			return r
	mid = int((l+r)/2)
	if arr[mid] <= val:
		return bin_search(arr,mid,r,val)
	else:
		return bin_search(arr,l,mid,val)
def search_leftmost(arr,val):
	def helper(arr,l,r,val):
		# print(arr)
		print(l,r)
		if arr[l] == val:
			return l
		if r -l <=1:
			if arr[r] == val:
				return r
			else:
				print("not found")
				return
		mid = int((r+l)/2)
		if arr[mid] >= val:
			return helper(arr,l,mid,val)
		else:
			return helper(arr,mid,r,val)
	return helper(arr,0,len(arr)-1,val)
def search_rightmost(arr,val):
	def helper(arr,l,r,val):
		# print(arr)
		print(l,r)
		if arr[r] == val:
			return r
		if r -l <=1:
			if arr[l] == val:
				return r
			else:
				print("not found")
				return
		mid = int((r+l)/2)
		if arr[mid] > val:
			return helper(arr,l,mid,val)
		else:
			return helper(arr,mid,r,val)
	return helper(arr,0,len(arr)-1,val)
def preorder_postorder(root,paths,parent,left,level):
	# if len(paths[node]) ==1 and node !=1 :
	# 	return [parent,left,level]
	l = 0
	queue = [root]
	while(queue!=[]):
		node = queue[-1]
		# print(queue,node)
		flag = 0
		for i in paths[node]:
			if i!=parent[node] and level[i]== sys.maxsize:
				parent[i] = node
				level[i] = level[node]+1
				flag = 1
				queue.append(i)
		if flag == 0:
			left[parent[node]] +=(1+left[node])
			queue.pop()
	# 		[parent,left,level] = helper(i,paths,parent,left,level)
	# 		l = left[i] + l +1
	# left[node] = l
	return [parent,left,level]
def nCr(n, r, p): #computes ncr%p
    # initialize numerator 
    # and denominator 
	if r == 0:
		return 1
	num = den = 1 
	for i in range(r): 
		num = (num * (n - i)) % p 
		den = (den * (i + 1)) % p 			 
	return (num * pow(den,p - 2, p)) % p 

def f_exp(p,k0,k1,l):
#computes p^k in log k time
	ans = 1
	k = k0-k1
	while(k != 0):
		if k%2 == 0:
			k = k//2
			p = p * p
		else:
			ans = ans *p
			k = (k -1)//2
			p = p * p
		if ans > l:
			ans = -1
			break
	return ans
def inp():
	return(int(input()))
def inlt(): 
	return(list(map(int,input().split())))
def insr():
	s = input()
	return(list(s[:len(s) - 1]))
def insr2():
	s = input()
	return((s[:len(s) - 1]))
def invr():
	return(map(int,input().split()))
 ############ ---- Input Functions ---- #######End
 # #####   
def pr_list(a):
	print(*a, sep=" ")
def main():
	# tests =  inp()
	tests = 1
	mod = 998244353
 
	limit = 10**18
	ans = 0
	for test in range(tests):
		[n,m] = inlt()
		a = inlt()
		b = inlt()
		last= {}
		for i in b:
			last[i] = -1
		for i in range(len(a)):
			if a[i] in last:
				last[a[i]] = i
		ans = 1
		flag = 0
		for i in range(1,m):
			if last[b[i]] == -1 or last[b[i-1]] == -1:
				flag = 1
				break
			if last[b[i]] < last[b[i-1]]:
				flag = 1
				break
			dec = 0
			f = 0
			for j in range(last[b[i]],last[b[i-1]],-1):
				if dec == 0 and a[j]< b[i]:
					ans = (ans *(f) )%mod
					dec = 1
				if a[j]<b [i-1]:
					flag = 1
					break
				f = f + 1
			if dec == 0:
				ans = (ans *(f) )%mod
			if flag == 1:
				break
		if flag != 1:
			for i in range(last[b[-1]], len(a)):
				if a[i] < b[-1]:
					flag = 1
					break
		if min(a) < b[0]:
			print(0)
		elif len(b) == 1:
			if b[0] not in a:
				print(0)
			else:
				print(1)
		elif flag == 1:
			print(0)
		else:
			print(ans)
		
 
		
		
if __name__== "__main__":
	main()