import math
from collections import Counter
n=int(input())
l=list(map(int,input().split()))
#l=[]
##for i in range(n):
#l+=[list(map(int,input().split()))int(input)]

count=0
l.sort()
j=0
l1=[0]*(n+1)
for i in range(0,n):
	if l[i]>j:
		j+=1
		count+=1
	
print(count)