n = int(input())
sum1=0
x=0
for x in range(0,n+1):
    if((sum1 + (x+1)*(x+2)/2)>n):
        print (x)
        break
    else:
        sum1 += (x+1)*(x+2)/2
