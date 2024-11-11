a,b,c,d=map(int,input().split())
m=max(((a//10)*3),(a-(a*c)//250))
v=max(((b//10)*3),(b-(b*d)//250))
if m>v:
	print('Misha')
elif m<v:
	print('Vasya')
else:
	print('Tie')