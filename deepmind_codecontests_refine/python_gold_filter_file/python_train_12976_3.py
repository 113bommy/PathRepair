"""
Brandt Smith, Lemuel Gorion and Peter Haddad

codeforces.com

Problem 92B
"""

import sys

n = list(int(x) for x in input().rstrip('\n'))

edge = False

count = 0

for i in range(len(n) - 1, -1, -1):
    if n[i] == 0 and not edge:
        count += 1
    elif n[i] == 0 and edge:
        count += 2
        
    elif n[i] == 1 and i != 0:
        count += 1
        edge = True
    elif n[i] == 1 and edge:
        count += 2
          

print(count)
