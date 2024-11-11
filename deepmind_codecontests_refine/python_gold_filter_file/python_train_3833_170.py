a,b,c=map(int,input().split())
print(b+c if a+b>=c-1 else 2*b+a+1)