
n = int(input())
s = list(map(int, input().split()))[:n]

m = 1001
d = abs(s[0] - s[n-1])
m = min(d,m)
idx1 =1
idx2 =n
for i in range(n-1):
    d = abs(s[i]-s[i+1])
    if m>d:
        m = d
        idx1 = i+1
        idx2 = i+2
print(idx1, idx2)