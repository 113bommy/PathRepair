'''input
5 8
'''
from math import log
n, m = map(int, input().split())
s = n*(log(m))
f = m*(log(n))
if(f==s):
    print('=')
elif(f>s):
    print('>')
else:
    print('<')