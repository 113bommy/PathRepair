import sys
import math
import bisect
from math import floor,sqrt,log
from collections import defaultdict
scanf=lambda n: [int(i) for i in sys.stdin.readline().split()][:n]
cin=lambda : map(int,sys.stdin.readline().split())
read_int=lambda : int(sys.stdin.readline())
read_string=lambda : sys.stdin.readline()
cout=lambda tt,x: sys.stdout.write("Case #"+str(tt)+": "+str(x)+'\n')
MOD=1000000007
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def mod_inverse(a, n):
    N = n
    xx = 0
    yy = 1
    y = 0
    x = 1
    while(n > 0):
        q = a // n
        t = n
        n = a % n
        a = t
        t = xx
        xx = x - q * xx
        x = t
        t = yy
        yy = y - q * yy
        y = t
    x %= N
    x += N
    x %= N
    return x

def sieve(n):
    prime = [True for i in range(n + 1)] 
    p = 2
    while (p * p <= n):  
        if (prime[p] == True):  
            for i in range(p * 2, n + 1, p): 
                prime[i] = False
        p += 1
    prime[0]= False
    prime[1]= False
    # return all prime numbers below n in O(n*log(log(n))
    return prime

def solve():
    n,W=cin()
    t1=W//2
    t2=W%2
    if t2!=0:
        t1+=1
    arr1,arr2=[],[]
    arr=scanf(n)
    f=0
    for i in range(n):
        if arr[i]>=t1 and arr[i]<=W:
            arr2.append(i+1)
        if arr[i]<=W:
            f=1
            arr1.append([arr[i],i])
    y,z=len(arr1),len(arr2)
    if f==0:
        print(-1)
    elif z!=0:
        print(1)
        print(arr2[0])
    else:
        cnt=0
        p=-1
        for i in range(y):
            cnt+=arr1[i][0]
            if cnt>=t1:
                p=i
                break
        if p==-1:
            print(-1)
        else:
            print(p+1)
            for i in range(p+1):
                print(arr1[i][1]+1,end=" ")
            print()
    #print(ans)
if __name__ == "__main__":
    #if ("in.txt" and "out.txt"):
    #    sys.stdin=open("in.txt",'r')
    #    sys.stdout=open("out.txt",'w')
    no_of_testcases=read_int()
    for testcase in range(1,no_of_testcases+1):
        #cout(testcase,solve())
        solve()
