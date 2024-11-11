n = int(input())
a = list(map(int , input().split(' ')))
a.sort()
l = [0]*333333
r = [0]*333333
for i in range(1 , n):
    l[i] = l[i - 1] + i * (a[i] - a[i - 1])
for i in range(n - 2, -1 , - 1):
    r[i] = r[i + 1] + (n - i - 1) * (a[i + 1] - a[i])
mn = 2222222222222222
ind = 0
for i in range(n):
    #print(l[i] , r[i])
    if mn > l[i] + r[i]:
        mn = l[i] + r[i]
        ind = i
print(a[ind])