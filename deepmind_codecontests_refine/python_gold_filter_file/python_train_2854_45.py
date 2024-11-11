n = int(input()) 
a = list(map(int, input().split()))
l = 2
maxl = 2
for i in range(2, n):
    if a[i] == a[i-2] + a[i-1]:
        l += 1
        if l>maxl: maxl=l
    else:
        if l > maxl: maxl = l
        l = 2
print(min(maxl, n))