t=int(input())
for j in range(t):
    s=input()
    a=list(s)
    l=len(a)
    for i in range(l):
        if i%2==0:
            if a[i]=='a':
                a[i]='b'
            else:
                a[i]='a'
        else:
            if a[i]=='z':
                a[i]='y'
            else:
                a[i]='z'
    s=" "
    for p in a:
        s+=p
    print(s)
            