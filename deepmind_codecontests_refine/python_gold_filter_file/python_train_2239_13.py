a,b,c = map(int,input().split())
print(min(a+b+c,a+c+c+a,b+c+c+b,a+a+b+b))