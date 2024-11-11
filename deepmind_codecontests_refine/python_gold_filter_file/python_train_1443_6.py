import collections
n = int(input())
l = list(input().split())
flg = True
c = collections.Counter(l)
if n%2 == 0:
  flg = all(i == 2 for i in c.values())
else:
  g = c.pop("0") == 1
  flg = all(i == 2 for i in c.values()) and g
#print(c)
print(2**(n//2)%1000000007 if flg else 0)
