import math
import sys
#####sorting a dictionary by the values#####
def dict_sort(ans):
    ans=sorted(ans.items(),reverse=True,key=lambda kv:(kv[1]))
##### naive method for testing prime or not#####
def is_prime(n):
    if n==1:
        return 0
    for i in range(2,int(math.sqrt(n))+1):
        if n%i==0:
            return False
    return True
#####greatest common divisor of two numbers#####
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
#####least common multiplyer of two numbers#####
def lcm(a,b):
    return (a*b)//gcd(a,b)
#####function that return all the letters#####
def alphabates():
    return "abcdefghijklmnopqrstuvwxyz"
#####binary search#####
def binary_search(ls,n,flag):
    low=0
    hi=n-1
    while(low<=hi):
        mid=(low+hi)//2
        if ls[mid]==flag:
            return mid
        elif ls[mid]>flag:
            hi=mid-1
        else:
            low=mid+1
    return -1
#####taking an array/list as input#####
def inp():
    ls=list(map(int,input().split()))
    return ls
#####taking multiple inputs#####
def mult_inp():
    return map(int,input().split())
#####Main function starts from here#####
n,k=mult_inp()
s=input()
freq=[0]*26
alp=alphabates().upper()
for i in s:
    freq[binary_search(alp,26,i)]+=1
#print(freq)
ans=0
freq.sort(reverse=True)
for i in freq:
    if i<=k:
        ans+=i*i
        k-=i
    else:
        ans+=k*k
        break
print(ans)