from sys import *
def check(n): 
  
     
    if (n <= 2): 
        print("No"); 
        return; 
  
    print("Yes")
    
    s1=(n*(n-1))//2; 
    s2=n; 
    print(n-1,end=' ');
    for i in range(1,n,1):
        print(i,end=' ')
    print()
    print(1,end=' ');
    print(n)

    
n=int(input())
check(n);
