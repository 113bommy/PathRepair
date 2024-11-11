import itertools
n = int(input())
petals = [int(i) for i in input().split()]
ans = 0
min_odd = 101
for i in petals:
    ans += i
    if i%2!=0 and i<min_odd:
        min_odd = i
if ans%2==0:
    if min_odd!=101:
        print(ans-min_odd)
    else:
        print(0)
else:
    print(ans)
