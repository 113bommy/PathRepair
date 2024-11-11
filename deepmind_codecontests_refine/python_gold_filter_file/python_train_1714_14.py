r,g,b = map(int,input().split())

l = sorted([r,g,b])
a,b,c = l
if c-a<=1:
    print((a+b+c)//3)
elif c>=2*(a+b):
    print(a+b)
else:
    print((a+b+c)//3)
