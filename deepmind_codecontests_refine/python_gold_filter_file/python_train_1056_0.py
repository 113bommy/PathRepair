n=int(input())
a=input()
c=0
for i in a:
    if i=='-':
        c=c-1
    else:
        c=c+1
    if c<0:
        c=0
if c<0:
    print(0)
else:
    print(c)
    