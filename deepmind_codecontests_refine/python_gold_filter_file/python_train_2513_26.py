# import os


n = int(input())
s = input()
sub = (n*(n+1))//2
c = 0
for i,l in enumerate(s):
    if int(l) % 2 != 0:
        c += i+1
print(sub-c)

