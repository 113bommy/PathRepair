import math as mt 
def polydiagonal(n):
    l=1;n=n*2
    ans=0
    ans=round(1/(mt.sin(mt.radians(180/n))),9);ans2=round(1/(mt.tan(mt.radians(180/n))),9)
    #print(ans,ans2)
    if(ans2==1):
        return 1
    return ans2
    
  
# Driver code  

#print(polydiagonal(n, a)) 
for _ in range(int(input())):
    print(polydiagonal(int(input())))
