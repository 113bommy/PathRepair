#####----ANTARA KUNDU----####
import random
from collections import Counter, defaultdict
from copy import deepcopy as dc
import math
try:
    t=int(input())
    for tt in range(1,t+1):
        n=int(input())
        a=list(map(int,input().split()))
        a.sort()
        for i in range(1,1+n//2):
            print(a[i],a[0])
        #x,y=map(int,input().split())
        
except EOFError as e:
    pass