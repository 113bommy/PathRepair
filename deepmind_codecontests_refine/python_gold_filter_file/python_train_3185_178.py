from sys import stdin,stdout
import math,bisect
from collections import Counter,deque,defaultdict
L = lambda:list(map(int, stdin.readline().strip().split()))
I = lambda:int(stdin.readline().strip())
S = lambda:stdin.readline().strip()
C = lambda:stdin.readline().strip().split()
M = lambda:map(int, stdin.readline().strip().split())

def pr(a):print(" ".join(list(map(str,a))))
#_________________________________________________#
 
import math
from collections import defaultdict as dd
# Function to check
# Log base 2
def solve(a):
    ans=0 
    c=0
    for i in range(len(a)):
        if a[i]=="*":
            break 
    
    for j in range(i+1,len(a)):

        if a[j]=="*":
            c=c+1
            ans = ans + (j - (i+c))
    return ans



l,m = M()
c=0
while l<=m:
    l=l*3 
    m=m*2 
    c=c+1 
print(c)