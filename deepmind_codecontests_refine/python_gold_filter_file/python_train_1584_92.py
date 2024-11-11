def isPrime(n):
    if(n==1 or n==0 or n==2 or n==3): 
        return True
    if(n==4):
        return False
    s = int(n**(1/2)) 
    for i in range(2,s+2):
        if(n%i == 0):
            #print(n,i)
            return False 
    return True 

n = int(input())
#print(isPrime(5)) 
for i in range(1,1000000):
    if(not(isPrime(i)) and not(isPrime(i+n))):
        print(i+n,i)
        break 
