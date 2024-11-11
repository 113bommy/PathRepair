a,b,c = map(int,input().split())

if c<=a+b:
    print(b+c)
else:
    print(a+b+1+b)