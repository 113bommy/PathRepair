n = int(input())
l = list(map(int,input().split()))
s = set(l)

if sum(l) == 2 * sum(s):
  flg = True
else:
  flg = False
#print(c)
print(2**(n//2)%(10**9+7) if flg else 0)
