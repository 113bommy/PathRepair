t=int(input())
for _ in range(t):
    m,n,a=map(int,input().split())
    h=a//m
    if ((h*m)+n)<=a and ((h)*m)+n>=0:
        print((h*m)+n)
    elif ((h-1)*m)+n<=a and ((h-1)*m)+n>=0:
        print(((h-1)*m)+n)