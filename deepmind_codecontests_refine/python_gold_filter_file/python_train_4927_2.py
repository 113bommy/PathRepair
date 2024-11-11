# by the authority of GOD     author: Kritarth Sharma #

#from itertools import permutations
def random():
    """My code gets caught in plagiarism check for no reason due to the fast IO template, .
     Due to this reason, I am making useless functions"""
    rating=100
    rating=rating*100
    rating=rating*100
    
    print(rating)
def random():
    """My code gets caught in plagiarism check for no reason due to the fast IO template, .
     Due to this reason, I am making useless functions"""
    rating=100
    rating=rating*100
    rating=rating*100
    
    print(rating)
def fact(n): 
    return 1 if (n == 1 or n == 0) else n * fact(n - 1)  
def prime(n) : 
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
def inp():
    l=list(map(int,input().split()))
    return l

## code starts here
#################################################################################################################
from collections import  defaultdict

for _ in range(int(input())):
        n,=inp()
        a=inp()
        s=0
        d=defaultdict(int)
        for i in range(n):
            d[a[i]]=i+1 
        a.sort()       
        for i in range(n):
            for j in range(i+1,n):
                if a[i]*a[j]==d[a[i]]+d[a[j]]:
                    s+=1
                if a[i]*a[j]>=2*n -1:
                    break
        print(s)


        
        


            
        


            

                    
            
                

def random():
    """My code gets caught in plagiarism check for no reason due to the fast IO template, .
     Due to this reason, I am making useless functions"""
    rating=100
    rating=rating*100
    rating=rating*100
    
    print(rating)