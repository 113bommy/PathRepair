from sys import stdin
input=lambda : stdin.readline().strip()
lin=lambda :list(map(int,input().split()))
iin=lambda :int(input())
main=lambda :map(int,input().split())
from math import ceil,sqrt,factorial,log
from collections import deque
from bisect import bisect_left
def solve():
	s=list(input())
	d={}
	for i in s:
		if i in d:
			d[i]+=1
		else:
			d[i]=1
	s=sorted(set(s))
	# print(s)
	n=len(s)
	t=ceil(n/2)
	ans1=[]
	ans2=[]
	t+=1
	for i in range(0,n,2):
		ans1.append(s[i])
	for i in range(1,n,2):
		ans2.append(s[i])
	# print(ans1,ans2)
	if len(ans1)>0 and len(ans2)>0:
		if abs(ord(ans1[0])-ord(ans2[-1]))!=1:
			ans=ans2+ans1
		elif abs(ord(ans1[0])-ord(ans2[0]))!=1:
			ans2.reverse()
			ans=ans2+ans1
		elif abs(ord(ans1[-1])-ord(ans2[-1]))!=1:
			ans2.reverse()
			ans=ans1+ans2
		else:
			ans=ans1+ans2
	else:
		ans=ans1+ans2
	for i in range(1,len(ans)):
		if abs(ord(ans[i])-ord(ans[i-1]))==1:
			print("No answer")
			return
	for i in range(len(ans)):
		ans[i]=ans[i]*d[ans[i]]
	print(''.join(ans))

qwe=1
qwe=int(input())
for _ in range(qwe):
	solve()