n,m = map(int,input().split())
a = sorted(list(map(int,input().split())))
b = sorted(list(map(int,input().split())))
if a[-1]>=b[0]:
	print(-1)
elif (a[0]*2<=a[-1]):
	print(a[-1])
elif (a[0]*2<b[0]):
	print(a[0]*2)
else:
	print(-1)