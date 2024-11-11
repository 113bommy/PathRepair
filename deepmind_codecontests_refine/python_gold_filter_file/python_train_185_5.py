a,b=map(int ,input().split())
x=int(pow(b,1/a)+0.00001)
while x>=1:
    if b%(x**a)==0:
        print(x)
        exit()
    x-=1

