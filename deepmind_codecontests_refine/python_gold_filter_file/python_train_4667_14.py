h,w=map(int,input().split())
l=[list(input()) for _ in range(h)]
l=[x for x in l if '#' in x]
l=[x for x in zip(*l) if '#' in x]
for i in zip(*l):
	print(''.join(i))
	