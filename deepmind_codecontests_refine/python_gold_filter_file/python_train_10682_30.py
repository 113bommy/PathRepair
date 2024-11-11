b=list (map (int,input().split()))
if b[2]<=b[1] and b[2]>=1:
	print(b[2])
elif b[2]>b[1] and b[2]<b[0]:
	print(b[1])
elif b[2]>=b[0]and b[2]<b[0]+b[1]:
	print(b[0]-b[2]+b[1])