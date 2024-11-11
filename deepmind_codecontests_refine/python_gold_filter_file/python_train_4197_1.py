import os
from math import*

s=input()
ans=[]
i=0
z=0
zz=0
while i<len(s)-1:
	if s[i]=="." or s[i]=="," or s[i]=="!" or s[i]=="?":
		if z==1:
			ans[-1]=s[i]
			ans.append(" ")
		else:
			ans.append(s[i])
			ans.append(" ")
			z=1
	elif s[i]==" ":
		if z==0:
			ans.append(" ")
			z=1
	else:
		ans.append(s[i])
		z=0
	i+=1
if s[-1]!=" ":
	ans.append(s[-1])
for x in ans:
	print(x,end='')

