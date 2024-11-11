a,b,c,d = [int(item) for item in input().split()]
x = max(3*a/10 , (a-(a*c/250)))
y = max(3*b/10 , (b-(b*d/250)))

if x>y:
    print("Misha")
elif x<y:
    print("Vasya")
else:
    print("Tie")