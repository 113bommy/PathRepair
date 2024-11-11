int_inp   = lambda: int(input()) #integer input
strng     = lambda: input().strip() #string input
strl      = lambda: list(input().strip())#list of strings as input
mul       = lambda: map(int,input().split())#multiple integers as inpnut
mulf      = lambda: map(float,input().split())#multiple floats as ipnut
seq       = lambda: list(map(int,input().split()))#list of integers
import math
from collections import Counter,defaultdict

a,b =mul()
m = list(input())
for i in range(a):
    if m[i]=='.':
        try:
            if m[i+b]=='1':
                m[i]='0'
                k = ''.join(m)
                k = k.replace('.','0')
                break
            elif m[i+b]=='0':
                m[i]='1'
                k = ''.join(m)
                k = k.replace('.','0')
                break
            else:
                m[i+b]='1'
                m[i]='0'
                k = ''.join(m)
                k = k.replace('.','0')
                break
        except:
            print("no")
            exit()
    elif m[i]!='.':
        try:
            if m[i+b]==m[i]:
                continue
            elif m[i+b]=='.':
                m[i+b]=str(1-int(m[i]))
                k = ''.join(m)
                k = k.replace('.','0')
                break
            else:
                k = ''.join(m)
                k = k.replace('.','0')
                break
        except:
            print("no")
            exit()
print(k)
