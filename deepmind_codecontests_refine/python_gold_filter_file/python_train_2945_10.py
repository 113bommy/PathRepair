import math 

def isPrime(n):

    if(n <= 1): 
        return False
    if(n <= 3): 
        return True
        
    if(n % 2 == 0 or n % 3 == 0): 
        return False
      
    for i in range(5,int(math.sqrt(n) + 1), 6):  
        if(n % i == 0 or n % (i + 2) == 0): 
            return False
      
    return True


def nextPrime(N):  
    if (N <= 1): 
        return 2
  
    prime = N 
    found = False
  
    while(not found): 
        prime = prime + 1
  
        if(isPrime(prime) == True): 
            found = True
  
    return prime


def solve(n):

    if isPrime(n):
        res = [1]*n

        for _ in range(n):
            print(*res)
        
        return

    row1n = [1]* (n-1)

    nxtPrime = nextPrime(n-1)

    res = nxtPrime - n+1

    while isPrime(res):
        nxtPrime = nextPrime(nxtPrime)

        res = nxtPrime - n+1
    

    row1n.append(res)

    rown = [res]* (n-1)

    nxtPrime = nextPrime(sum(rown))

    res = nxtPrime- sum(rown)

    while isPrime(res):
        nxtPrime = nextPrime(nxtPrime)

        res = nxtPrime - sum(rown)

    rown.append(res)

    for _ in range(n-1):
        print(*row1n)
    
    print(*rown)

    return


t = int(input())

for _ in range(t):
    n = int(input())

    solve(n)