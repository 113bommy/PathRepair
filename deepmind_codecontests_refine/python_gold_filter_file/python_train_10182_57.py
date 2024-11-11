import sys, re
from collections import deque, defaultdict, Counter
from math import ceil, sqrt, hypot, factorial, pi, sin, cos, radians
from itertools import permutations, combinations, product, accumulate
from operator import itemgetter, mul
from copy import deepcopy
from string import ascii_lowercase, ascii_uppercase, digits
from fractions import gcd

def input(): return sys.stdin.readline().strip()
def INT(): return int(input())
def MAP(): return map(int, input().split())
def LIST(): return list(map(int, input().split()))
sys.setrecursionlimit(10 ** 9)
INF = float('inf')
mod = 10 ** 9 + 7

N = INT()
gsb_A = LIST()
gsb_B = LIST()
gsb_delta = {}
# for i in range(3):
# 		if min(gsb_A[i], gsb_B[i]) in gsb_delta:
# 			gsb_delta[min(gsb_A[i], gsb_B[i])] = max(max(gsb_A[i], gsb_B[i]), gsb_delta[min(gsb_A[i], gsb_B[i])])
# 		else:
# 			gsb_delta[min(gsb_A[i], gsb_B[i])] = max(gsb_A[i], gsb_B[i])
# print(gsb_delta)
dp = [0] * (N+1)
for i in range(N+1):
	if i-gsb_A[0] >= 0:
		dp[i] = max(dp[i], dp[i-gsb_A[0]]+gsb_B[0])
	if i-gsb_A[1] >= 0:
		dp[i] = max(dp[i], dp[i-gsb_A[1]]+gsb_B[1])
	if i-gsb_A[2] >= 0:
		dp[i] = max(dp[i], dp[i-gsb_A[2]]+gsb_B[2])
	if i >= 1 and i-gsb_A[0] < 0 and i-gsb_A[1] < 0 and i-gsb_A[2] < 0:
		dp[i] = dp[i-1]+1
# print(dp)
# print(dp[N])
M = max(N, dp[N])
dp = [0] * (M+1)
for i in range(M+1):
	if i-gsb_B[0] >= 0:
		dp[i] = max(dp[i], dp[i-gsb_B[0]]+gsb_A[0])
	if i-gsb_B[1] >= 0:
		dp[i] = max(dp[i], dp[i-gsb_B[1]]+gsb_A[1])
	if i-gsb_B[2] >= 0:
		dp[i] = max(dp[i], dp[i-gsb_B[2]]+gsb_A[2])
	if i >= 1 and i-gsb_B[0] < 0 and i-gsb_B[1] < 0 and i-gsb_B[2] < 0:
		dp[i] = dp[i-1]+1
# print(dp)
print(max(M, dp[M]))
