a,b,c=[int(x) for x in input().split()]
if a==b:
    print(a+b+2*c)
elif a>b:
    print(b*2+2*c+1)
else:
    print(a*2+2*c+1)