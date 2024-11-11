n=int(input())
a=list(map(int,input().split()))
a=[0]+a
s=[0]*(n+1)
for i in range(n,0,-1):
    if sum(s[i::i])%2==a[i]:
        s[i]=0
    else:
        s[i]=1
print(sum(s))
b=''
for i in range(1,n+1):
    if s[i]==1:
        b+=str(i)+' '
if b:
    print(b)