a,b,c=map(int,input().split())
print(min(a+2*c+a,a+b+c,b+2*c+b,2*a+2*b))