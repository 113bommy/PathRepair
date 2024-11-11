#!/usr/bin/env python
# -*- coding: utf-8 -*-
a,b,c=map(int,input().split())
k=0
l=0
for d in list(map(int,input().split())):
	if d==1:
		if b>0:
			b-=1
		elif b==0 and c>0:
			c-=1
			l+=1
		elif l>0:
			l-=1
		else: 
			k+=1
	if d==2:
		if c>0:
			c-=1
		else:
			k+=2
print(k)
			
		
