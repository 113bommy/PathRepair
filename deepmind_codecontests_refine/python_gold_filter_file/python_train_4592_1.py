import math
def checkprime(a):
    flag=0
    c=int(math.sqrt(a))
    for i in range(2,c+1):
        if(a%i==0):
            flag=1
    if(flag>0):
        return "NO"
    else:
        return "YES"
t=int(input())
for i in range(0,t):
    t1,t2=input().split()
    t1=int(t1)
    t2=int(t2)
    diff=t1+t2
    if(t1-t2>1):
        print("NO")
    else:
        print(checkprime(diff))
                
            
    
