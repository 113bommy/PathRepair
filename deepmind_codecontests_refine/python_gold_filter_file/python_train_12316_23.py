k,l,m,n,c=int(input()),int(input()),int(input()),int(input()),0
# if min(k,l,m,n,d)==d:
# 	print(0)
# 	exit()
for i in range(1,int(input())+1):
	if i%k==0 or i%l==0 or i%m==0 or i%n==0:
		c+=1
print(c) 