# Python3 code to find largest prime 
# factor of number 
from collections import Counter
import math 
  
# A function to print all prime factors of  
# a given number n 
def primeFactors(n): 
      
    # Print the number of two's that divide n
    list=[]
    while n % 2 == 0: 
        
        list.append(2)
        n = n / 2
          
    # n must be odd at this point 
    # so a skip of 2 ( i = i + 2) can be used 
    for i in range(3,int(math.sqrt(n))+1,2): 
          
        # while i divides n , print i ad divide n 
        while n % i== 0: 
            
            list.append(i)
            n = n / i 
              
    # Condition if n is a prime 
    # number greater than 2 
    if n > 2: 
        
        list.append(n)
    return list

  
  
#write your main here
#find the count of maximum factor in the b
n,b=map(int,input().split())

m_fact=primeFactors(b)
#counter = Counter(m_fact)
#print(counter)
ll=[]
#print(m_fact)
for fact in m_fact:
    #print(fact)
    div=0
    bb=b
    while (bb%fact)==0:
        div+=1
        bb=int(bb//fact)
    #print(div)
    #print(div)

    t_count=int(0)
    num=n
    #print(num)
    while num>=fact:
        t_count+=int(num//fact)
        num=(num//fact)
        #print(num)
    #print(t_count)

    ll.append(t_count//div)
    #print(ll)
print(min(ll))