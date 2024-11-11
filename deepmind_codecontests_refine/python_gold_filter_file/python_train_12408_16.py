from collections import defaultdict as dd

n1,n2 = map(int,input().split())

flag=0

for i in range(n1,n2+1):
	s = str(i);m1 = dd(int)
	for j in range(len(s)):
		if m1[s[j]]==0:
			m1[s[j]]+=1
		else:
			break
		if j==len(s)-1:
			print(i)
			flag=1
			break
	if flag==1:
		break
if flag==0:
	print(-1)
		