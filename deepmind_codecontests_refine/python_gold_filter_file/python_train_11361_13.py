t=int(input())
alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for i in range(t):
    n,k=map(int,input().split())
    f=n//k
    r=''
    j=-1
    for j in range(k-1):
        r+=alphabet[j]*f
    r+=alphabet[j+1]*(n-f*(k-1))
    print(r)