n,i,t,r=int(input()),0,0,[]
while n>=0:
	i+=1
	n-=i*i
	t+=i
	m=n//t
	r+=[(m+i,i),(i,m+i)][m==0:]*(m*t==n>=0)
for p in[(len(r),'')]+sorted(r):print("%d %s"%p)