import collections
 
n = int(input())
ln = list(map(int, input().split()))
m = int(input())
lm = list(map(int, input().split()))
 
c1 = collections.Counter(lm)
c2 = collections.Counter(ln)
 
for i in c1.keys():
    if c2[i] < c1[i]:
        print("NO")
        exit()
 
print("YES")