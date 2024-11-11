t = int(input())
while t>0:
    t-=1
    n = int(input())
    a = list(map(int,input().split()))
    s = 0
    t1 = 0
    for i in a:
        s+=i 
        t1^=i
    print(2)
    print(t1,(s+t1))