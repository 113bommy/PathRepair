'''Author- Akshit Monga'''
from sys import stdin, stdout
input = stdin.readline

def gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a % b)

t = int(input())
for _ in range(t):
    n=int(input())
    if (n-1)%2:
        print((n-1)//2,n//2,1)
        continue
    i=3
    while 1:
        if i!=n-i-1 and gcd(i,n-i-1)==1:
            print(i,n-i-1,1)
            break
        i+=1