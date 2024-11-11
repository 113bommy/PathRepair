n=int(input())
s=0
if n%2==0:
    m=10
    while(n>=m):
        s+=n//m
        m*=5
print(s)