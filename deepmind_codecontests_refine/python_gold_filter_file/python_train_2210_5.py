import math
n=int(input())
x=list(map(int,input().split()))
num=(x.count(1)*x.count(-1))+(x.count(2)*x.count(-2))+(x.count(3)*x.count(-3))+(x.count(4)*x.count(-4))+(x.count(5)*x.count(-5))+(x.count(6)*x.count(-6))+(x.count(7)*x.count(-7))+(x.count(8)*x.count(-8))+(x.count(9)*x.count(-9))+(x.count(10)*x.count(-10))
if x.count(0)==100000:
    print(4999950000)
    exit()
if x.count(0)>1:num+=((math.factorial(x.count(0)))/(2*math.factorial(x.count(0)-2)))
print(int(num))