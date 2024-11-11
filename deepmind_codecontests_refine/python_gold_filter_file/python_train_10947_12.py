import math
t=int(input())
for _ in range(t):
    ans=1
    counter=0
    n=int(input())
    while(n%3==0 or n%5==0):
        if(n%3==0):
            n=n//3
            counter+=2
        if(n%5==0):
            n=n//5
            counter+=3
    if(math.log(n,2)==int(math.log(n,2))):
        print(counter+int(math.log(n,2)))
    else:
        print(-1)
