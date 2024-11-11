a,b,c,d=list(map(int,input().split()))
maxmisha=max((3*a)/10,a-(a/250)*c)
maxvasya=max((3*b)/10,b-(b/250)*d)
if maxvasya>maxmisha:
    print("Vasya")
elif  maxvasya<maxmisha:
    print("Misha")
else:
    print("Tie")