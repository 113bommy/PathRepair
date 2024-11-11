#   When in doubt, collections.Counter()

#   input()
#   int(input())
#   input().split()
#   list(map(int, input().split()))
#   for _ in range(t):

import math
import collections
import bisect

def arrPrint(a):
    return " ".join([str(i) for i in a])

def gridPrint(a):
    return "\n".join([" ".join([str(j) for j in a[i]]) for i in range(len(a))])

def isPalindrome(s):
    for i in range(len(s)//2):
        if not s[i] == s[-i-1]:
            return False
    return True

def primeCheck(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n%i == 0:
            return False
    return True

def solve(n):
    return (n+2)//2

t = int(input())
for _ in range(t):
    n = int(input())
    print(solve(n))
