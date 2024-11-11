import sys
import random
n = int(input())
a = [int(x) for x in input().split()]

def flat():
    for i in range(1, n):
        #print(i)
        if a[i] != a[0]:
            return False
    return True

if n<3 or flat():
    print(-1)
    sys.exit()
    
def sorted_asc():
    for i in range(1, n):
        if a[i] > a[i-1]:
            return False
    return True

def sorted_desc():
    for i in range(1, n):
        if a[i] < a[i-1]:
            return False
    return True

"""
if sorted_asc() or sorted_desc():
    i = 1
    while a[i]==a[0]:
        i += 1
    print(1, i+1)
    sys.exit()
"""

for i in range(0,100000):
    #print(random.random())
    be = random.randrange(0, n)
    en = be
    while en == be:
        en = random.randrange(0, n)
    if a[be]==a[en]:
        continue
    a[be], a[en] = a[en], a[be]    
    if not sorted_asc() and not sorted_desc():
        print(be+1, en+1)
        sys.exit()
    a[be], a[en] = a[en], a[be]    

print(-1)
