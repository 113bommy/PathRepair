from collections import Counter
input()
c=Counter(input())
a=1
for i in c.items():
    a*=(1+i[1])
    a%=10**9+7
print(a-1)