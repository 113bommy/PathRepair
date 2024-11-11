#from https://ikatakos.com/pot/programming_algorithm/contest_history/atcoder/2019/0106_educational_dp_3
from  itertools import accumulate
mod=1000000007
n=int(input())
s=input()
dp=[1]*n
for i in range(n-1):
    if s[i]==">":
        dp.reverse()
        dp=list(accumulate(dp[:-1]))
        dp.reverse()
    else:
        dp=list(accumulate(dp[:-1]))
    for j in range(len(dp)):
        dp[j]%=mod
print(dp[0])
