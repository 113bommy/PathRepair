import random
from collections import Counter
#uglypairs
n=int(input())
def isugly(s,n):
    for i in range(1,n):
        if abs(ord(s[i])-ord(s[i-1]))==1:
            return True
    return False
for _ in range(n):
    count=Counter(input())
    candidate=list(count.keys())
    valid='No answer'
    for _ in range(100):
        random.shuffle(candidate)
        if not isugly(candidate,len(candidate)):
            valid=''.join([count[x]*x for x in candidate])
            break
    print(valid)

