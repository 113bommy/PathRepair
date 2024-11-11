import math
a, b, c, d = map(int, input().split())
#print(round((a-c)*math.sqrt(2),6),round(math.sqrt((a-c)**2+(b-d)**2),6))
if a == c:
    print(a + d - b, b, a + d - b, d)
elif b==d:
    print(a, c - a + b, c, c - a + b)
elif (round(abs(a-c)*math.sqrt(2),6)==round(math.sqrt((a-c)**2+(b-d)**2),6)):
    print(a,d,c,b)
else:
    print(-1)