#   When in doubt, collections.Counter()

#   input()
#   int(input())
#   input().split()
#   list(map(int, input().split()))
#   for tt in range(t):

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

def solve(n, k, a):
    ans = 0
    for i in range(k, n+1):
        sm = sum(a[0:i])
        ans = max(ans, sm/i)
        for j in range(i, n):
            sm -= a[j - i]
            sm += a[j]
            ans = max(ans, sm/i)
    return round(ans, 7)

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
print(solve(n, k, a))
