n = int(input());
a = list(map(int,input().split()));

def gcd(a,b):
    if(b==0):
        return a;
    else:
        return gcd(b,a%b)

for i in range(n):
    while(a[i]%2==0):
        a[i]=a[i]/2;
    while(a[i]%3==0):
        a[i]=a[i]/3
flag = True;
for i in range(1,n):
    if(a[i]!=a[0]):
        flag = False;
        break
if(flag == True):
    print("Yes");
else:
    print("No");
