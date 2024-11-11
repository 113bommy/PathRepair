n = int(input())
l = sorted(list(map(int,input().split())))
s = 0
for i in range(n//2):
    s += (l[i]+l[n-i-1])**2
print(s)