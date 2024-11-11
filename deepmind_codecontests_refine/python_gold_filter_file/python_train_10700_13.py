n, k = map(int, input().split())
p = list(map(int,input().split()))
s = [0] * (n-k+1)
s_0 = sum(p[0:k])
s[0] = s_0
for i in range(n-k):
    s[i+1] = s[i] + p[k+i] - p[i]

print((k+max(s))/2)