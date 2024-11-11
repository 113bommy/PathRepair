# import sys
# sys.stdin=open('input.in','r')
# sys.stdout=open('output.out','w')
suc=[]
los=[]
k1=0
k3=0
a=0
b=0
n=int(input())
for x in range(n):
	t,s,l=map(int,input().strip().split()[:3])
	if t==1:
		suc.append([s,l])
		a+=1
	else:
		los.append([s,l])
		b+=1
for x in suc:
	k1+=x[0]
for y in los:
	k3+=y[0]
if k1>=a*5:
	print('LIVE')
else:
	print('DEAD')
if k3>=b*5:
	print('LIVE')
else:
	print('DEAD')