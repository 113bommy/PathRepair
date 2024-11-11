n=int(input())
a=sorted(map(int,input().split()))[::-1]
j=i=0
while n:i+=a[i]>i;j+=a[j]>=i;n-=1
print('SFeicrosntd'[(a[i-1]^i|j^i)&1::2])
