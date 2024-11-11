from math import *
from collections import *
from sys import *
import string
import re
t=stdin.readline
p=stdout.write
def GI(): return map(int, input().strip().split())
def GS(): return map(str, t().strip().split())
def IL(): return list(map(int, t().strip().split()))
def SL(): return list(map(str, t().strip().split()))

a=sorted([(len(input())-2,i) for i in 'ABCD'])
c=0
if a[0][0]*2<=a[1][0]: c+=1
if a[-2][0]*2<=a[-1][0]: c+=2
print(['C',a[0][1],a[-1][1],'C'][c])