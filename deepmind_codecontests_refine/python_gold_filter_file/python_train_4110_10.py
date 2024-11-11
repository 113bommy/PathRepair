a,b,c,d = input().split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
Vasya_score = max((3*b)/10,(b-(b/250)*d))
Misha_score =  max((3*a)/10,(a-(a/250)*c))
if Misha_score > Vasya_score:
    print("Misha")
elif Misha_score==Vasya_score:
    print("Tie")
else:
    print("Vasya")