r,d,x=map(int,input().split())
t=x
for i in range(1,11):
    t=r*t-d
    print(t)