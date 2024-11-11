# Python program to print prime factors 

import math 
l=[]
# A function to print all prime factors of 
# a given number n 
def primeFactors(n): 
	
	# Print the number of two's that divide n 
	while n % 2 == 0: 
		l.append(2)
		n = n / 2
		
	# n must be odd at this point 
	# so a skip of 2 ( i = i + 2) can be used 
	for i in range(3,int(math.sqrt(n))+1,2): 
		
		# while i divides n , print i ad divide n 
		while n % i== 0: 
			l.append(int(i))
			n = n / i 
			
	# Condition if n is a prime 
	# number greater than 2 
	if n > 2: 
		l.append(int(n))
		
# Driver Program to test above function 

n = int(input())
primeFactors(n) 

s =list(set(l))
mul =1
ma = 0
if(n==1):
    print(1,0)
    exit()
for i in s:
    c= l.count(i)
    ma = max(ma,c)
    mul = mul*i
c=0
while(2**c<ma):
    c+=1

fl =0

for i in s:
    if(l.count(i)!=2**c):
        fl=1
if(fl==1):
    c=c+1
print(mul,c)




