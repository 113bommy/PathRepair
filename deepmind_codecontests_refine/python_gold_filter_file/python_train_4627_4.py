n,b = map(int, input().split())
a = list(map(int, input().split()))

#First approac Naive
# print (max(b//a[i]*a[j] + b%a[i] for j in range(n) for i in range(j+1) ))

#Second approach
x = 0 #max selling
res = b;

for i in range(n-2, -1, -1):
    x = max(x, a[i+1])
    res = max(res, (b//a[i]*x + b%a[i]) )

print (res)