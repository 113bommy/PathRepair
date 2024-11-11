import math
e=10**9+7
n=int(input())
xs=math.factorial(n)
fi=math.factorial(5)
si=math.factorial(6)
se=math.factorial(7)
fie=math.factorial(n-5)
see=math.factorial(n-7)
sie=math.factorial(n-6)
a=xs//(fi*fie)
b=xs//(si*sie)
c=xs//(se*see)
print(a+b+c)