def sumofdigits(n):
    n=str(n)
    sum1=0
    for i in n:
        sum1+=int(i)
    return sum1

n=int(input())
c=[]
for i in range(1,182):
    if(i==n):
        break
    if(i==(sumofdigits(n-i))): 
        c.append(n-i)
        
print(len(c))
for i in range(1,len(c)+1):
    print(c[-1*i])
    
    


