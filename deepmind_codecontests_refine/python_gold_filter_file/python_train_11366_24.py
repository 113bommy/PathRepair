def gcd(x,y):
    while (y):
        x,y = y, x%y
    return x
a,b,n = map(int, input().split())

i=1

while n>=0:
    if i%2==1:
        n -= gcd(a,n)
    else:
        n -= gcd(b,n)
    i+=1
if i%2==1:
    print(0)
else:
    print(1)