n, k = map(int, input().split())
e=1
while pow(k, e) <= n:
  e+=1
print(e)