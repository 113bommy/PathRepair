a,b,t = map(int,input().split(' '))
for i in range(10):
    t = a*t-b
    print(t)