n,m,k = input().split(' ')
n = int(n)
m = int(m)
k = int(k)
a = list(map(int,input().split(' ')))
b = list(map(int,input().split(' ')))

aa = min(a)
bb = max(b)

#print(aa,bb)

cnt = k // aa
r = k % aa
#print(cnt,bb)
buy = cnt * bb

if buy + r > k:
  print((bb * cnt) + r)
else:
  print(k)