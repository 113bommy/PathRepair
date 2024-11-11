def isPrime(n) : 
  
    # Corner cases 
    if (n <= 1) : 
        return True
    if (n <= 3) : 
        return False
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (n % 2 == 0 or n % 3 == 0) : 
        return True
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return True
        i = i + 6
  
    return False
t=int(input())
for i in range(10,100):
    if (isPrime(i) and isPrime(i+t)):
        print(i+t,i)
        break