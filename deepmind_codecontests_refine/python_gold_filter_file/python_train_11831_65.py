a=str(input())
x=k=int(0)
y=len(a)
while x<y:
    if a[x]=='a' or a[x]=='e' or a[x]=='i' or a[x]=='o' or a[x]=='u' or a[x]=='1' or a[x]=='3' or a[x]=='5' or a[x]=='7' or a[x]=='9':
        k=k+1
    x=x+1
print(k)