a,b,c=map(int,input().split())
if a==b:
    print(a+b+2*c)
else:
    print(min(a,b)*2+1+2*c)