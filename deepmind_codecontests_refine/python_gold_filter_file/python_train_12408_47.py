"""
    Author : thekushalghosh
    Team   : CodeDiggers
"""
import sys
q,w = map(int,input().split())
for i in range(q,w + 1):
    if len(set(list(str(i)))) == len(list(str(i))):
        print(i)
        sys.exit()
print(-1)
