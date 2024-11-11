import math
from operator import mul
from functools import reduce 

def isPrime(n) : 
  
    # Corner cases 
    if (n <= 1) : 
        return False
    if (n <= 3) : 
        return True
  
    # This is checked so that we can skip  
    # middle five numbers in below loop 
    if (n % 2 == 0 or n % 3 == 0) : 
        return False
  
    i = 5
    while(i * i <= n) : 
        if (n % i == 0 or n % (i + 2) == 0) : 
            return False
        i = i + 6
  
    return True



T = int(input())

for _ in range(T):
    N = int(input())
    n = N
    zz = False
    for i in range(2, math.floor(n**.5) + 1):
        if n % i == 0:
            n = n//i
            for j in range(2, math.floor(n**.5) + 1):
                if n % j == 0 and j != i:
                    n = n//j
                    if n != i and n != j and n > 1:
                        print ('YES')
                        print ('{} {} {}'.format(i, j, n))
                        zz=True
                        break 
            if zz:
                break 

    if zz:
        continue
    print ('NO')



'''

    # find the prime divisors of n
    exp = []
    while n > 1:
        for m in range(2, n + 1):
            if isPrime(m) and (n % m) == 0:
                e = 1
                while True:
                    if n % m**e == 0:
                        e += 1
                    else:
                        exp.append((m, e - 1))
                        break 
                break 
        n = n//(m**(e - 1))
        if len(exp) >= 3:
            break 

    abc = []
    if len(exp) >= 3:
        print ('YES')
        # 
        abc.append(exp[0][0])
        abc.append(exp[1][0])
        abc.append(N//(abc[0]*abc[1]))
        print (' '.join(map(str, abc)))
        continue 
    if len(exp) == 2:
        if sum([j for i, j in exp]) >= 4:
            print ('YES')
            #
            abc.append(exp[0][0])
            abc.append(exp[1][0])
            abc.append(N//(abc[0]*abc[1]))
            print (' '.join(map(str, abc)))
            continue 
    if len(exp) == 1:
        if sum([j for i, j in exp]) >= 6:
            print('YES')
            abc.append(exp[0][0])
            abc.append(exp[0][0]**2)
            abc.append(N//(abc[0]*abc[1])) 
            print (' '.join(map(str, abc)))         
            continue 
    print ('NO')

'''


