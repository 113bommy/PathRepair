x,y,z,t1,t2,t3 = map(int,input().split())
dis = abs(x-y)
te = (abs(z-x))*t2+dis*t2+3*t3
ts = dis*t1

if(te<=ts):
	print('yes')
else:
	print('no')