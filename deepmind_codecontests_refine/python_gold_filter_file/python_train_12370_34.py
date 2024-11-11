n=int(input())
if n==0:print(0)
k=-2
bi=''
while n!=0:
    bi+=str(n%abs(k))
    if k<0:n=-(-n//k)
    else:n=n//k
print(bi[::-1])
