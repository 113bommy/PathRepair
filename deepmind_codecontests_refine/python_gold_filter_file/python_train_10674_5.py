a=int(input())
b=int(a/7)
c=int(a%7)
if c==6:
    print(b*2+1)
else:
    print(b*2)
if c>=2:
    print(b*2+2)
elif c==1:
    print(b*2+1)
else:
    print(b*2)
