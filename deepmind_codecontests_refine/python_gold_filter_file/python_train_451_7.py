n = int(input())
l = []
s = 0
for i in range(n):
    l.extend(map(int,input().split()))
# print(l)
le = sum(l[::2])
r = sum(l[-1::-2])
# print(le,r)
if (le>n//2):
    s += n-le
else:
    s += le
if (r>n//2):
    s += n-r
else:
    s += r
print(s)