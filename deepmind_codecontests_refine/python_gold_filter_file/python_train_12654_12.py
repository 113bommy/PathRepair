n = int(input())
if n==1:
	print(1)
	exit()

arr=[]

while n>0:
	str=input()
	t=[int(e) for e in str.split()]
	arr.append(t)
	n-=1

n=len(arr)

for r in arr:
	if 0 in r:
		zero_row=r
	else:
		non_zero_row=r
		
s = sum(non_zero_row)
re = s

for e in zero_row:
	re-=e

zero_row[zero_row.index(0)]=re

if re<=0:
	print(-1)
	exit()
	
flag=True

s = sum(arr[0])

for i in range(1,n):
	if(sum(arr[i])!=s):
		flag=False
	
	if(flag==False):
		break

for j in range(0,n):
	ss=0
	for i in range(0,n):
		ss+=arr[i][j]
	
	if(ss!=s):
		flag=False
		
	if(flag==False):
		break
		
		

if(flag==True):
	ss=0
	for i in range(0,n):
		ss+=arr[i][i]

	if(ss!=s):
		flag=False
	
if(flag==True):
	ss=0
	for i in range(0,n):
		ss+=arr[i][n-1-i]

	if(ss!=s):
		
		flag=False
		
if(flag==True):
	print(re)
else:
	print(-1)




		

