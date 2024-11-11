import sys
import math
from collections import defaultdict,Counter

input=sys.stdin.readline
def print(x):
    sys.stdout.write(str(x)+"\n")

# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# mod=pow(10,9)+7
t=int(input())
for i in range(t):
	n,k=map(int,input().split())
	a=list(map(int,input().split()))
	c=Counter(a)
	if k==1:
		if len(c)>1:
			ans=-1
		else:
			ans=1
	else:
		ans=1+max(0,int(math.ceil((len(c)-k)/(k-1))))
	print(ans)