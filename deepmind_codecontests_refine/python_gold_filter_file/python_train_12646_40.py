import math
import sys

n=int(input())
s=input()
m=set()
alfa="abcdefghijklmnopqrstuvwxyz"
for i in s:
    m.add(i.lower())
fail=0
for i in alfa:
    if i.lower() not in m:
        fail=1
if fail==1:
    print("NO")
else:
    print("YES")
