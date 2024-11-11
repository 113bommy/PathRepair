n,m,a,b = [int(x) for x in input().split()]

if(a*m <= b):
    print(n*a)
else:
    print(min(a*(n%m),b) + b * int(n/m))