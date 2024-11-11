import math
n,m=map(int,input().split())
if(n>=0 and n<=1 and m==0):
    print(0)
elif(n>=0 and m>=0):
    if(abs(n)>=abs(m)): 
        print(math.floor(4*(abs(n)-1))+1) if((abs(n)-1)>=0) else print(1)
    else:
        print(math.floor(4*(abs(m)-1))+2) if((abs(m)-1)>=0) else print(2)
elif(n<0 and m>=0):
    if(abs(n)<=abs(m)):
        print(math.floor(4*(abs(m)-1))+2) if((abs(m)-1)>=0) else print(2)
    else:
        print(math.floor(4*(abs(n)-1))+3) if((abs(n)-1)>=0) else print(3)
elif(n<=0 and m<0):
    if(abs(n)>=abs(m)):
        print(math.floor(4*(abs(n)-1))+3) if((abs(n)-1)>=0) else print(3)
    else:
        print(math.floor(4*(abs(m)-1))+4) if((abs(m)-1)>=0) else print(4)
elif(n>=0 and m<=0):
    #if(abs(n)<abs(m)):
    #    print(math.floor(4*(abs(n)-1))+5) if((abs(n)-1)>=0) else print(5)
    #else:
    print(math.floor(4*(abs(m)-1))+4) if((abs(m)-1)>=0) else print(4)