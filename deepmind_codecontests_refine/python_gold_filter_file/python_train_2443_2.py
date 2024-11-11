#In The Nam Of GOd

n=int(input());
if(n==1):
    print("YES",1);
    exit();
if(n==2):
    print("YES",1,2,sep="\n");
    exit();
if(n==4):
    print("YES",1,3,2,4,sep="\n");
    exit();
for i in range(2,n):
    if n%i==0:
        print("NO");
        exit();

print("YES",1,sep="\n");
for i in range (2,n):
    print((i*pow(i-1,n-2,n))%n);
print(n);
