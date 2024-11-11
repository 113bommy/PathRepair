#########################################################################################################\
#########################################################################################################
###################################The_Apurv_Rathore#####################################################
#########################################################################################################
#########################################################################################################

import sys,os,io
from math import log, gcd, ceil
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop


import math 



def ncr(n, r, p):  #using fermat's little theorem
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
                      p - 2, p)) % p

  
def primeFactors(n): 
    l = []
    while n % 2 == 0: 
        l.append(2)
        n = n / 2
          
    for i in range(3,int(math.sqrt(n))+1,2): 
          

        while n % i== 0: 
            l.append(int(i))
            n = n / i 
    if n > 2: 
        l.append(n)
    return list(set(l))
    
def power(x, y, p) : 
	res = 1
	x = x % p 
	if (x == 0) : 
		return 0
	while (y > 0) : 
		if ((y & 1) == 1) : 
			res = (res * x) % p 
		y = y >> 1	 # y = y/2 
		x = (x * x) % p 		
	return res 


def si():
    return input()

# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def prefix_sum(arr):
    r = [0] * (len(arr)+1)
    for i, el in enumerate(arr):
        r[i+1] = r[i] + el
    return r

def divideCeil(n,x):
    if (n%x==0):
        return n//x
    return n//x+1

def ii():
    return int(input())

def li():
    return list(map(int,input().split()))

def ws(s): sys.stdout.write(s + '\n')
def wi(n): sys.stdout.write(str(n) + '\n')
def wia(a): sys.stdout.write(' '.join([str(x) for x in a]) + '\n')


if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")
t = 1
# t = int(input())
for _ in range(t):
    u,v = li()
    if (u-v)%2==1 or u>v:
        print(-1)
        continue
    if (u==0 and v==0):
        print(0)
        continue
    if (u==v):
        print(1)
        print(u)
        continue
    diff = (v-u)//2
    temp = diff
    diff = bin(diff)[2:][::-1]
    binu = bin(u)[2:][::-1]
    # print(diff)
    # print(binu)
    f = 0
    for i in range(min(len(diff),len(binu))):
        if (diff[i]==binu[i]=='1'):
            print(3)
            print(temp,temp,u)
            f = 1
            break
    if (f==0):
        print(2)
        print(u+temp,temp)


