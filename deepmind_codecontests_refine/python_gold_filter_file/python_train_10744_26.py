import sys
import math
from collections import Counter
import bisect


ma=lambda:map(int,input().split())
inp=lambda:[int(i) for i in input().split()]
s=sorted





for _ in range(int(input())):
	A=inp()
	A.sort(reverse=True)
	if(A[1]+A[2]+1>=A[0]):
		print("Yes")
	else:
		print("No")


