# http://codeforces.com/problemset/problem/227/B

n = int(input())
lis = [int(x) for x in input().split()]
m = int(input())
search = [int(x) for x in input().split()]
x = y = 0
a = [0]*(n+1)
for i in range(n):
    a[lis[i]] = i+1
for c in search :
    x+=a[c]
    y+= n-a[c]+1

print(x,y)
