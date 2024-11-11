import math

def Chocolate(s,a,b,c):
    x = math.floor(s/c)
    v =math.floor(x/a)*b
    if x < a:
        num = x
    else:
        num = x + v
    print(num)
for _ in range(int(input())):
	s,a,b,c=map(int, input().split())
	Chocolate(s ,a ,b ,c)