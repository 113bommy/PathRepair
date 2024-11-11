a,b,c,d=list(map(int,input().split()))
ms=max(0.3*a,a-(a*c/250))
vs=max(0.3*b,b-(b*d/250))
if ms>vs:
    print("Misha")
elif ms<vs:
    print("Vasya")
else:
    print("Tie")