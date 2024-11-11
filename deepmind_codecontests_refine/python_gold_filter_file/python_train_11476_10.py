from math import *
# from sys import stdin,stdout

def binarySearch(arr,x,i):
	l=i
	r=len(arr)-1 
	while l <= r: 
		mid = (l + r)//2; 
		if arr[mid] == x: 
			return mid 
		elif arr[mid] < x: 
			l = mid + 1
		else: 
			r = mid - 1
	return -1

def js(arr,x):
	l=0
	r=len(arr)-1
	ans=-1
	while(l<=r):
		m=(l+r)//2
		if(arr[m]<=x):
			ans=m
			l=m+1
		else:
			r=m-1
	return ans

def jg(arr,x):
	l=0
	r=len(arr)-1
	ans=-1
	while(l<=r):
		m=(l+r)//2
		if(arr[m]>=x):
			ans=m
			r=m-1
		else:
			l=m+1
	return ans

# def ceil(a,b):
# 	if a%b == 0:
# 		return int(a/b)
# 	else:
# 		return (a//b + 1)

# from collections import deque

# n,m,k=map(int,input().split())
# ar=list(map(int,input().split()))

# q=[]
# sm=[0]*(m+1)
# for i in range(m+1):
# 	queue = deque()
# 	q.append(queue)


# ans=1
# for i in range(m+1)
# 	q[ar[i]].append(i)
# 	if(len(sm[ar[i]])==0):
# 		sm[ar[i]].append(1)
# 	else:

# 	while q[ar[i]]:


n,m=map(int,input().split())
a=list(map(int,input().split()))
if(n>1000):
	print(0)
else:
	ans=1
	for i in range(n):
		for j in range(i+1,n):
			ans=(ans*abs(a[i]-a[j]))%m
	print(ans)