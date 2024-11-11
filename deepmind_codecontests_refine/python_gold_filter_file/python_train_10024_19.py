n = int(input())
l = list(map(int, input().split()))
mx, mn, mx_ar, mn_ar = 0, 101, 0, 0
for i in range(n):
    if l[i] > mx:
        mx = l[i]
        mx_ar = i
    if l[i] <= mn:
        mn = l[i]
        mn_ar = i
 
n = n-1
if mn_ar < mx_ar:
    mn_ar += 1
 
ind = mx_ar + (n  - mn_ar)
 
print(ind)