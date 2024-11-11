a=int(input())
l=list(map(int,input().split()))
lw,h=a,0
for i in range(1,a):
	if l[i-1]>l[i]:
		lw=i-1
		break
for i in range(a-2,-1,-1):
	if l[i+1]<l[i]:
		h=i+1
		break
if lw==a and h==0:
	lw=hw=0
else:
	v=l[lw:h+1]
	l=l[:lw]+v[::-1]+l[h+1:]
for i in range(1,a):
	if l[i-1]>l[i]:
		print("no")
		break
else:
	print("yes")
	print(lw+1,h+1)