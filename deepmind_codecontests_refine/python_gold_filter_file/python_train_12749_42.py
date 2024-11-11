import sys
import math

def main():
    pass

def binary(n):
    return (bin(n).replace("0b", ""))

def decimal(s):
    return (int(s, 2))

def pow2(n):
    p = 0
    while n > 1:
        n //= 2
        p += 1
    return (p)

def isPrime(n):
    if (n == 1):
        return (False)
    else:
        root = int(n ** 0.5)
        root += 1
        for i in range(2, root):
            if (n % i == 0):
                return (False)
        return (True)

def sinp():return sys.stdin.readline().strip()
def iinp():return int(input())
def ninp():return map(int,sys.stdin.readline().strip().split())
def linp():return list(map(int,sys.stdin.readline().strip().split()))

n,l=ninp()
a=linp()
a.sort()
ans=diff=0
for i in range(len(a)-1):
    diff=a[i+1]-a[i]
    if(diff>ans):
        ans=diff
ans=ans/2
if(a[0]-0>ans and a[0]!=0):
    ans=a[0]
if(l-a[len(a)-1]>ans and a[len(a)-1]!=l):
    ans=l-a[len(a)-1]
print(ans)