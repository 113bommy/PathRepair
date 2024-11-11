a,b,c,d = list(map(int,input().split()))
if max((3*a)//10,a-(a*c)//250) > max((3*b)//10,b-(b*d)//250):
    print("Misha")
elif max((3*a)//10,a-(a*c)//250) < max((3*b)//10,b-(b*d)//250):
    print("Vasya")
else:
    print("Tie")