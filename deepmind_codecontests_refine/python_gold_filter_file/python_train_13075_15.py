#Winners never quit, Quitters never win............................................................................
from collections import deque as de
import math
from collections import Counter as cnt
from functools import reduce
from typing import MutableMapping
from itertools import groupby as gb
from fractions import Fraction as fr

def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))
class My_stack():
    def __init__(self):
        self.data = []
    def my_push(self, x):
        return (self.data.append(x))
    def my_pop(self):
        return (self.data.pop())
    def my_peak(self):
        return (self.data[-1])
    def my_contains(self, x):
        return (self.data.count(x))
    def my_show_all(self):
        return (self.data)
    def isEmpty(self):
      return len(self.data)==0

arrStack = My_stack()    
def decimalToBinary(n): 
    return bin(n).replace("0b", "")

def isPrime(n) : 
	if (n <= 1) : 
		return False
	if (n <= 3) : 
		return True

	
	if (n % 2 == 0 or n % 3 == 0) : 
		return False

	i = 5
	while(i * i <= n) : 
		if (n % i == 0 or n % (i + 2) == 0) : 
			return False
		i = i + 6

	return True

def get_prime_factors(number):
    prime_factors = []
    while number % 2 == 0:
        prime_factors.append(2)
        number = number / 2
    for i in range(3, int(math.sqrt(number)) + 1, 2):
        while number % i == 0:
            prime_factors.append(int(i))
            number = number / i

    if number > 2:
        prime_factors.append(int(number))

    return prime_factors
def get_frequency(list):
    dic={}
    for ele in list:
        if ele in dic:
            dic[ele] += 1
        else:
            dic[ele] = 1
    return dic
def Log2(x): 
    return (math.log10(x) / 
            math.log10(2)); 

def isPowerOfTwo(n): 
    return (math.ceil(Log2(n)) == math.floor(Log2(n))); 
def ceildiv(x,y): return (x+y-1)//y #ceil  function gives wrong answer after 10^17 so i have to create my own :)
# because i don't want to doubt on my solution of 900-1000 problem set.  
def di():
    return map(int, input().split())
def li():
    return list(map(int, input().split()))
#here we go......................
#Winners never quit, Quitters never win

n,m=di()
s=input()
t=input()
mn=n
index=0
for i in range(m-n+1):
    temp=0
    #print(i, "idex")
    for j in range(i,i+n):
        if t[j] !=s[j-i]:
            temp+=1
    if temp < mn:
        mn=temp
        index=i
#print(temp, index)
ans=[]
for k in range(index,index+n):
    #print(t[k], s[k-index])
    if t[k] !=s[k-index]:
        
        
        ans.append(k-index+1)
print(mn)
print(*ans)
    
    
        
        







    
        
    



        
        
        
                
                

        

