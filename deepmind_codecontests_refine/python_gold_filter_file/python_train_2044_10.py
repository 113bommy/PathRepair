n=int(input())
n2,a,b=(n*n+n)//2,[],0
print(n2%2)
n2//=2
while n2>=n:
    a,n2,n,b=a+[n],n2-n,n-1,b+1
if n2!=0:
    a,b=a+[n2],b+1
print(b,' '.join(map(str,a)))