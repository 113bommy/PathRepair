import sys,math,io,os,time,itertools,collections
mod=10**9+7
sys.setrecursionlimit(10000)
i=sys.stdin.readline
p=sys.stdout.write
#use sys.stdout.write() (remember to convert to str b4 and concatenate "\n")
global start,end

#binary search
def isin(l,x):
    left=0
    right=len(l)-1
    if x<l[0]:
        return -1
    while left<=right:
        mid=left + (right -left)//2
        if l[mid]==x:
            return mid
        elif l[mid]<x:
            ans=mid
            left=mid+1
        else:
            right=mid-1
    return ans

#is palindrome or not
def ispal(l):
    n=len(l)
    for i in range(n//2+1):
        if l[i]!=l[n-i-1]:
            return False
    return True

#coordinate compression
def ccarray(l):
    d={l[k]:k for k in range(len(l))}
    m=sorted(d)
    return [d[m[k]] for k in range(len(l))]

#checks if prime or not
def is_prime(n):
    if n<=3:
        return n>1
    if n%2==0 or n%3==0:
        return False
    k=5
    while k**2<=n:
        if n%k==0 or n%(k+2)==0:
            return False
        k+=6
    return True

#sieve of eratosthenes
def sieve(n):
    prime=[True for k in range(n+1)]
    p=2
    while p*p<=n:
        if prime[p]==True:
            for k in range(p*p,n+1,p):
                prime[k]=False
        p+=1

def main():
    n=int(i())
    a=[int(k) for k in i().split()]
    o=a.count(1)
    t=a.count(2)
    x=o
    if o%2==0 and o!=0:
        x=o-1
    l=["2"]*min(1,t) + ["1"]*x + ["2"]*(t-min(1,t)) + ["1"]*(o-x)
    p(" ".join(l)+"\n")

t=1
#t=int(i())
start=time.perf_counter()
for _ in range(t):
    main()
end=time.perf_counter()
#print(end-start)