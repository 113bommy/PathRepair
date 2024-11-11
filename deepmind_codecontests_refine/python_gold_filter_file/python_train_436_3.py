"""609C"""
# import math
# import sys
def main():
	# n ,m= map(int,input().split())
	# a = list(map(int,input().split()))
	n = int(input())
	a = list(map(int,input().split()))
	add = 0
	mx = -5
	mn = 1000000001
	cnt = 0
	for i in range(n):
		if i>0 and a[i-1]==-1 and a[i]!=-1:
			if a[i]>mx:
				mx = a[i]
			if a[i]<mn:
				mn = a[i]
		elif i<n-1 and a[i+1]==-1 and a[i]!=-1:
			if a[i]>mx:
				mx = a[i]
			if a[i]<mn:
				mn = a[i]
	avg = (mx+mn)//2
	# print(mn,mx)
	ans = -1
	for i in range(1,n):
		if a[i-1]==-1:
			a[i-1]=avg
		if a[i]==-1:
			a[i]=avg
		ans = max(ans,abs(a[i]-a[i-1]))
	print(ans,avg)
		

	
	return


# main()
def test():
	t = int(input())
	while t:
		main()
		t-=1
test()
