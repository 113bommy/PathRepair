from collections import deque
from collections import OrderedDict
import math
 
import sys
import os
from io import BytesIO
import threading
import bisect
 
 
import heapq

#sys.stdin = open("F:\PY\\test.txt", "r")
input = lambda: sys.stdin.readline().rstrip("\r\n") 



n = int(input())

ar = list(map(int, input().split()))
dp=[0]*4
for i in range(n):
    dp[ar[i]]+=1
if dp[1]+dp[2]==0 or dp[1]+dp[3]==0 or dp[2]+dp[3]==0:
    print(0)
else:
    print(n-max(dp[1],dp[2],dp[3]))
