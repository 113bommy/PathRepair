n=int(input())
a=n//2
if n%2==0:
    print(n*(n+2)//4)
else:
    print(a*(a+1)+(n+1)//2)