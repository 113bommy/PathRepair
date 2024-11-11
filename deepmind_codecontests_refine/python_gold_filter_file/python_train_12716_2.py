a,b,c=(int(i) for i in input().split())
if(b>a):
    print((2*a)+1+(2*c))
elif(a>b):
    print((2*c)+(2*b)+1)
else:
    print(a+b+(2*c))