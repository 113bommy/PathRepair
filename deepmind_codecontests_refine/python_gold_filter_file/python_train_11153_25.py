import sys
import math
input = sys.stdin.readline

n=int(input())

s=input()
R=[0,0,0]
G=[0,0,0]
B=[0,0,0]

for i in range(n):
	if s[i]=="R":
		if i%3==0:
			R[0]+=1
		elif i%3==1:
			R[1]+=1
		else:
			R[2]+=1

	if s[i]=="G":
		if i%3==0:
			G[0]+=1
		elif i%3==1:
			G[1]+=1
		else:
			G[2]+=1

	if s[i]=="B":
		if i%3==0:
			B[0]+=1
		elif i%3==1:
			B[1]+=1
		else:
			B[2]+=1


Rneed=[]
Gneed=[]
Bneed=[]

for i in range(3):

	Rneed.append(n//3-R[i])
	Gneed.append(n//3-G[i])
	Bneed.append(n//3-B[i])

	if n%3==1 and i%3==0:
		Rneed[-1]+=1
		Gneed[-1]+=1
		Bneed[-1]+=1
	elif n%3==2 and i%3<2:
		Rneed[-1]+=1
		Gneed[-1]+=1
		Bneed[-1]+=1

x1=Rneed[0]+Gneed[1]+Bneed[2]
x2=Rneed[0]+Gneed[2]+Bneed[1]
x3=Rneed[1]+Gneed[0]+Bneed[2]
x4=Rneed[1]+Gneed[2]+Bneed[0]
x5=Rneed[2]+Gneed[0]+Bneed[1]
x6=Rneed[2]+Gneed[1]+Bneed[0]


m=min(x1,x2,x3,x4,x5,x6)
trans=-1

fin=[]
if x1==m:
	trans=x1
	for i in range(n):
		if i%3==0:
			fin.append("R")
		elif i%3==1:
			fin.append("G")
		else:
			fin.append("B")
elif x2==m:
	trans=x2
	for i in range(n):
		if i%3==0:
			fin.append("R")
		elif i%3==1:
			fin.append("B")
		else:
			fin.append("G")
elif x3==m:
	trans=x3
	for i in range(n):
		if i%3==0:
			fin.append("G")
		elif i%3==1:
			fin.append("R")
		else:
			fin.append("B")
elif x4==m:
	trans=x4
	for i in range(n):
		if i%3==0:
			fin.append("B")
		elif i%3==1:
			fin.append("R")
		else:
			fin.append("G")
elif x5==m:
	trans=x5
	for i in range(n):
		if i%3==0:
			fin.append("G")
		elif i%3==1:
			fin.append("B")
		else:
			fin.append("R")
elif x6==m:
	trans=x6
	for i in range(n):
		if i%3==0:
			fin.append("B")
		elif i%3==1:
			fin.append("G")
		else:
			fin.append("R")

print(trans)
print(''.join(fin))