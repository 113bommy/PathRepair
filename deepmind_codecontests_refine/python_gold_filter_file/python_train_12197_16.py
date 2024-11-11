k=int(input())
n,m=1,k
v=['a','e','i','o','u']

for i in range(5,int(k**0.5)+1):
    if k%i==0:
        n=i
        m=k//i
        break
if n>=5 and m>=5:
    s=[['b' for i in range(n)] for j in range(m)]
    for i in range(len(s)):
        p=i%5
        for j in range(len(s[0])):
            s[i][j]=v[p]
            p=(p+1)%5
    for i in range(len(s)):
        print(''.join(s[i]),end="")
    print()
else:
    print(-1)