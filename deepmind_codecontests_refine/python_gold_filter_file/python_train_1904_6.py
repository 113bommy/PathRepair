import math
import os
import random
import re
import sys
 
for _ in range(int(input())):
    n, m = map(int, input().rstrip().split())
    a = tuple(map(int, input().rstrip().split()))
    
    if sum(a)==m: print('YES')
    else: print('NO')