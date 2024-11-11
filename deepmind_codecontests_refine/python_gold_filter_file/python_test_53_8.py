# cook your dish here
from collections import Counter, deque
from re import L
from sys import stdin, stdout
import math
from collections import defaultdict
from typing import AnyStr, DefaultDict

# int(stdin.readline())
# map(int, stdin.readline().split())
# list(map(int, stdin.readline().split()))
# list(input())

for _ in range(int(stdin.readline())):
    n,k=input().split(" ")

    
    s=list(input())

    odd=[]
    even=[]

    n=int(n)

    for i in range(int(n)):
        if s[i]!=k:
            if (i+1)%2==0:
                even.append(i+1)
            else:
                odd.append(i+1)
    
    if len(even)==0 and len(odd)==0:
        print(0)
    elif len(even)==0 and len(odd)!=0:
        print(1)
        if n%2==0:
            print(n)
        else:
            print(n-1)
    elif len(even)!=0 and len(odd)==0:
        print(1)
        if n%2==0:
            print(n-1)
        else:
            print(n)
    
    else:
        if s[-1]==k:
            print(1)
            print(n)
        else:
            ind=-1
            for i in range(n-2,-1,-1):
                if s[i]==k:
                    ind=i
                    break
            if ind==-1:
                print(2)
                print(n,n-1)
            else:
                cc=False
                for j in range(ind+2,n+1):
                    if j%(ind+1)==0:
                        cc=True
                        break
                if cc==False:
                    print(1)
                    print(ind+1)
                else:
                    print(2)
                    print(n,n-1)






    


                    

                    



    



            




