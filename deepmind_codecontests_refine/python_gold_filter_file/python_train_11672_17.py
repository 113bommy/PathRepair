#!/usr/bin/env python
import sys
import math

N, M, K, L = [int(i) for i in input().split()]
ans = int((K+L+M-1)//M)
if ans*M>N: ans=-1
print(ans)
