h=min([int(x) for x in input().split(' ')])
h+=1
v=[(x,h-x-1) for x in range(h)]
print(h)
for c in v:
	print(c[0],c[1])