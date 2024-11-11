#82A
import math
a=['Sheldon', 'Leonard', 'Penny', 'Rajesh','Howard']
n=int(input())

x=math.ceil(math.log(n/5+1,2))#现在第x轮
y=n-5*(2**x-1)#现在这轮的第几个
z=2**(x-1)
print(a[math.ceil(y/z)-1])