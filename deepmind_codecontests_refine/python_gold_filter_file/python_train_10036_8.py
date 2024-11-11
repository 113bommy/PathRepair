from fractions import gcd
def lcm(x, y): lcm = (x*y)//gcd(x,y); return lcm
x,y,a,b=map(int,input().split())
print(b//lcm(x,y)-(a-1)//lcm(x,y))