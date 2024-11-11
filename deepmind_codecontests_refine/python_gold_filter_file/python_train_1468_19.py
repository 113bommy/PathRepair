from sys import stdin, stdout 
from bisect import bisect_left, bisect_right
from collections import defaultdict
import math
cin = stdin.readline
def cout(x):
	stdout.write(str(x)+'\n')

def nexint():
    return int(stdin.readline())
def readline():
    return map(int,stdin.readline().split())
def readlist():
    return list(map(int,stdin.readline().split()))

def sorted_indexes(arr):
    return sorted(range(len(arr)),key=arr.__getitem__)
def printr(arr):
    [stdout.write(str(x)+' ')   for x in arr]
    cout('')

def find_lt(a, x):#'Find rightmost value less than x'
    i = bisect_left(a, x)
    if i:
        return a[i-1]
    raise ValueError

def find_gt(a, x):#'Find leftmost value greater than x'
    i = bisect_right(a, x)
    if i != len(a):
        return a[i]
    raise ValueError

# ---------------------Template ends-------------sdpt,sdpt131[Sudipta Banik]---------------------



def isv(c):
    return c == 'a' or c == 'e' or c=='i' or c=='o' or c=='u'


# print(isv('a'))

s = input()
n = len(s)


brk = False
i = 0
while (i<n-1):
    if isv(s[i]):
        i+=1
    else:
        if isv(s[i+1]) or s[i]=='n':
            i+=1
        else:
            brk = True
            break
        
if not (s[n-1]=='n' or isv(s[n-1])):
    brk = True
    
if brk:
    cout("NO")
else:
    cout("YES")


