# math_prob.py
for z in range(int(input())):
    n = int(input())
    f = 10e9
    s = 0
    
    for i in range(n):
        x,y = map(int,input().split())
        f = min(f,y)
        s = max(s,x)
    if n==1:
        print(0)
    else:
        if s-f>=0:
            print(s-f)
        else:
            print(0)