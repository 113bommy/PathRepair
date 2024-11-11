from collections import Counter

N = int(input())
S = input()
P = 10**9 + 7

dic = Counter(S)
rlt = 1

for k in dic:
  rlt = rlt*(dic[k]+1) % P
  
print(rlt-1)