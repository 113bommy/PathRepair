n,a,b = map(int,input().split())

m = (a+b)%n
if(m !=0):
    print(m)
else:
    print(n)