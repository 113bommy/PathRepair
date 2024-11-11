a,b,c,d = map(int,input().split())
m = max(0.3*a, a-(a//250)*c)
v =max(0.3*b, b-(b//250)*d)
if v > m:
    print("Vasya")
elif m > v:
    print("Misha")
else:print("Tie")