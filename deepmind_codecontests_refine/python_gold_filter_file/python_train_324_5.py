n=int(input())
l=list(map(int,input().split()))
c1=c2=0
l1=[]
l2=[]
for i in l:
	if i%2==0:
		c1+=1
		l1.append(i)
	else:
		c2+=1
		l2.append(i)
if c1>c2+1:
	l1.sort()
	print(sum(l1[:c1-c2-1]))
elif c2>c1+1:
	l2.sort()
	print(sum(l2[:c2-c1-1]))
else:
	print(0)