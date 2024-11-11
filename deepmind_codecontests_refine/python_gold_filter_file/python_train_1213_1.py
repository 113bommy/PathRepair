#JMD
#Nagendra Jha-4096

#a=list(map(int,sys.stdin.readline().split(' ')))
#n,k,s= map(int, sys.stdin.readline().split(' '))

import sys
import math

#import fractions
#import numpy

###Defines...###
mod=1000000007

###FUF's...###
def nospace(l):
	ans=''.join(str(i) for i in l)
	return ans



##### Main ####
n,a,b= map(int, sys.stdin.readline().split(' '))
s=list(map(int,sys.stdin.readline().split(' ')))
val=math.ceil(sum(s)-(s[0]*a/b))
del s[0]
s.sort()
s=s[::-1]
count=0
sm=0
for ss in s:
	count+=1
	sm+=ss
	if(sm>=val):break
if(val<=0): count=0
print(count)
