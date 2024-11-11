s=input()
for _ in range(int(input())):
    l,r,k=map(int,input().split(' '))
    k%=(r-l+1)
    l-=1;r-=1;
    b = s[l:r+1]
    b = b[(r-l+1)-k:] + b[:(r-l+1)-k]
    s = s[:l]+b+s[r+1:]
print(s)