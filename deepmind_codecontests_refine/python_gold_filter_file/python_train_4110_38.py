l=[int(x) for x in input().split()]
a=l[0]
b=l[1]
c=l[2]
d=l[3]
x=max((3*a)/10,(a-((a/250)*c)))
y=max((3*b)/10,(b-((b/250)*d)));
if(x>y):
    print("Misha")
elif(x<y):
    print("Vasya");
else:
    print("Tie");
