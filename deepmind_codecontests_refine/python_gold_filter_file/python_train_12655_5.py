n, k = map(int,input().split())
a = list(map(int,input().split()))
b = []
s = 0
r = str(a[0])
for i in range(n-1):
    if a[i]+a[i+1] < k:
        s = s + (k - (a[i+1]+a[i]))
        #print(s)
        a[i+1] = a[i+1] + (k - a[i]- a[i+1])
    r = r + ' ' + str(a[i+1])
print(s)
print(r)