from collections import defaultdict
from itertools import accumulate
import sys
input = sys.stdin.readline
'''
for CASES in range(int(input())):
n, m = map(int, input().split())
n = int(input())
A = list(map(int, input().split()))
S = input().strip()
sys.stdout.write(" ".join(map(str,ANS))+"\n")
'''
inf = 100000000000000000  # 1e17
mod = 998244353

n = int(input())
A = list(map(int, input().split()))
# print(*A)

l=[-1]*(n+1)
r=[-1]*(n+1)
F=[0]*(n+1)
cnt=[0]*(n+1)


for num,a in enumerate(A):
    if l[a]==-1:
        l[a]=num
    r[a]=num

for i in range(n-1,-1,-1):
    F[i]=F[i+1]
    nowcol=A[i]
    cnt[nowcol]+=1
    if i==l[nowcol]:
        F[i]=max(F[i],F[r[nowcol]+1]+cnt[nowcol])
    else:
        F[i]=max(F[i],cnt[nowcol])

print(n-F[0])