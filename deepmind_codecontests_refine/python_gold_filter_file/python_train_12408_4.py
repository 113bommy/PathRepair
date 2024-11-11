import sys
input = sys.stdin.readline

from collections import Counter

l,r=map(int,input().split())

for i in range(l,r+1):
    C=Counter(str(i))
    if max(C.values())==1:
        print(i)
        sys.exit()

print(-1)
