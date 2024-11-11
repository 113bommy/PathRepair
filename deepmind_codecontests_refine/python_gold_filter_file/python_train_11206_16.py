from collections import *
n , k = input().split();
n = int(n)
k = int(k)
cnt = Counter()
a = min(k + 1 , 100005)
fl = 1
for i in range(1 , a):
    if(cnt[n%i] != 0 ):
        fl = 0
        break
    else:
        cnt[n%i] = 1

if(fl):
    print("Yes\n")
else:
    print("No\n")
