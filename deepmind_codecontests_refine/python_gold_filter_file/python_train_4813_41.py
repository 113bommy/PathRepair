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

def s(n):
	f=[]
	for i in range(1,int(n**(0.5))+1):
		if(n%i==0):
			if(n%(n//i)==0 and n%(n//i)!=i):
				f.append(n//i)
			f.append(i)
	f.sort()
	return f


t=[[0]]
for i in range(1,15000):
	t.append(s(i))
# print(t[228])


for __ in range(int(input())):
	a,b,c=map(int,input().split())
	ans=9999999
	r1=0
	r2=0
	r3=0
	for i in range(1,15000):
		a1=t[i][js(t[i],a)]
		a2=t[i][jg(t[i],a)]
		r2=i
		if(c%i==0):
			r3=c
		else:
			if(c<i):
				# print("sdf")
				r3=i
			else:
				if(ceil(c/i)*i - c<c-(c//i)*i):
					# print("sdfs")
					r3=ceil(c/i)*i
				else:
					r3=(c//i)*i
		if(a-a1<a2-a):
			r1=a1
		else:
			r1=a2

		if(abs(a-r1)+abs(b-r2)+abs(c-r3)<ans):
			ans1=r1
			ans2=r2
			ans3=r3
			ans=abs(a-r1)+abs(b-r2)+abs(c-r3)
		# break
	print(ans)
	print(ans1,ans2,ans3)


	