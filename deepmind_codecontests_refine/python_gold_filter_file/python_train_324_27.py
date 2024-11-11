# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n=int(input())
a=list(map(int,input().split()))
a.sort()
b,c=0,0
d=[]
e=[]
for i in range(len(a)):
	if a[i]&1:
		b+=1
		d.append(a[i])
	else:
		c+=1
		e.append(a[i])
d.sort()
e.sort()		
if b==c-1 or c==b-1 or b==c:
	print('0')
elif b==len(a) or c==len(a):
	print(sum(a[0:len(a)-1]))	
else:
	if b>c:
		print(sum(d[0:b-c-1]))
	else:
		print(sum(e[0:c-b-1]))	

