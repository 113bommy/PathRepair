n = int(input())
a = list(map(int,input().split(' ')))
ma = 0
mi = 0
for i in range(1,len(a)-1):
  if a[i] < a[i-1] and a[i] < a[i+1]:
    ma += 1
  if a[i] > a[i-1]and a[i] > a[i+1]:
    mi += 1
print(ma + mi)
