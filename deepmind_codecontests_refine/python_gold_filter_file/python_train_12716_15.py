a,b,c=map(int,input().split())
if a==b:
    print(c*2+2*min(a,b))
elif a<b:
    print(c*2+2*a+1)
else:
    print(c*2+b*2+1)