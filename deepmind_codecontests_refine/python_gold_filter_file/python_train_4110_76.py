a,b,c,d=list(map(int,input().split()))
s=max((3*a)//10,a-((a//250)*c))
t=max((3*b)//10,b-((b//250)*d))
if s<t:
    print("Vasya")
elif s>t:
    print("Misha")
else:
    print("Tie")