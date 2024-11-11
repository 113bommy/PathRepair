mod=10**(9)+7
n=int(input())
s=input()
cc=0
cbc=0
res=0
x=1;
for i in range(n-1,-1,-1):
    if s[i]=='c':
        cc=(cc+x)%mod 
    elif s[i]=='b':
        cbc=(cbc+cc)%mod 
    elif s[i]=='a':
        res=(res+cbc)%mod
    else:
        res=(res*3+cbc)%mod 
        cbc=(3*cbc+cc)%mod
        cc=(3*cc+x)%mod
        x=(x*3)%mod
print(res)