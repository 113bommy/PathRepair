import heapq;import sys;import math;from collections import deque;from bisect import bisect_left,bisect_right;I=sys.stdin.readline;II=lambda :int(I());IN=lambda x:map(int,x.split());FN=lambda x:map(float,x.split());L=lambda x:list(IN(x));M=1000000007;P=print;T=True;F=False
for _ in range(II()):
	n,k,x=IN(I());x-=1
	s=I()
	# l=s[:-1].split('a')
	#print(l)
	st=[]#;v=1
	i=0;lc=s[0];li=0
	while(i<n):
		while(s[i]==lc):
			i+=1
		st.append(i-li)
		lc=s[i]
		li=i
	zx=len(st)-1
	if(s[-2]=='a'):
		zx-=1
	wt=[1];f=-1
	for i in range(zx,-1,-2):
		twt=wt[-1]*(st[i]*k+1)
		wt.append(twt)
		if(x<twt):
			f=i
			break
	res=[]#;print(wt,st,f)
	i=0#;pos=0
	if(s[0]=='a'):
		i+=1
		res.append('a'*st[0])
	while(i<len(st)):
		if(i>=f):
			break
		# pos+=1
		i+=1
		if(i<len(st)):
			res.append('a'*st[i])
		i+=1
	while(i<len(st)):
		q,x=divmod(x,wt[-2])
		wt.pop()
		res.append(q*'b')
		i+=1
		if(i<len(st)):
			res.append('a'*st[i])
		i+=1
	print(*res,sep='')



