a,b,c = map(int,input().split())
if c <= a+b:
    print(c+b)
else:
    print(b*2+a+1)