n=int(input())
s=input()
a=['G','R','B']
from itertools import permutations as per
# print(list(per(a)))
ans=10000000
str=""
for k in list(per(a)):
    ans1=0
    for i in range(n):
        if s[i]!= k[i%3]:
            ans1+=1
    if ans>ans1:
        ans=ans1
        str=k

print(ans)
for i in range(n):
    print(str[i%3],end="")