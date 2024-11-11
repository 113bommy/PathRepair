import math
s=''
n=int(input())
t=1
i=0
while n>5*t:
    n-=5*t
    i+=1
    t*=2
t=math.ceil(n/(2**i))
l=["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]
print(l[t-1])
    
