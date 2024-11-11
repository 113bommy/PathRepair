n,m,a,b=map(int,input().split())
import math
#If all rides are by normal ticket
cost1=n*a
cost2=0
#If all rides are by special ticket
if(n>=m):
    cost2=n//m*b+(n%m)*a
    cost2=min(cost2,math.ceil(n/m)*b)
elif(n<m):
    cost2=min(b,n*a)
print(min(cost1,cost2))