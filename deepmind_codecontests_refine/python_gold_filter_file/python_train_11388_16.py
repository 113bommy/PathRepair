import sys
f = sys.stdin
#f = open("input.txt", "r")
n = int(f.readline().strip())
a = [int(i) for i in f.readline().strip().split()]
cnt = dict.fromkeys(a)
for i in cnt:
    cnt[i] = a.count(i)
if (sum(cnt.values()) - max(cnt.values()) < sum(cnt.values())//2 or a.count(a[0]) == len(a)) and len(a) >= 2:
    print("NO")
else:
    print("YES")