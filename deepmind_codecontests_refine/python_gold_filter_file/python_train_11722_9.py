n,k=(int(x) for x in input().split())
s=[int(x) for x in input().split()]
a=0
for i in range(k):
   a+=s[i]
a/=k
x=a
if n==k:
    print(a*k)
else:
    for i in range(n-k):
        x=(x*k+s[i+k]-s[i])/k
        a+=x
    a/=(n-k+1)
    print(a*k)