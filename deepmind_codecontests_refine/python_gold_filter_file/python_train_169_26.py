from collections import Counter
from itertools import combinations
import sys
num=input()
string=input()
if len(string)==2:
	print(string)
	sys.exit(0)
ans=dict()
for i in range(len(string)-1):
	if string[i:i+2] not in ans.keys():
		ans[string[i:i+2]]=1
	else:
		ans[string[i:i+2]]+=1
print(max(ans,key=ans.get))