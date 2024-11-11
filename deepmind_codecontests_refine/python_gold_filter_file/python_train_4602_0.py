from sys import stdin
tt=int(stdin.readline().strip())
for t in range(tt):
    n=int(stdin.readline().strip())
    s=list(map(int,stdin.readline().strip().split()))
    im1=0
    im2=0
    pa1=0
    pa2=0
    s=list(set(s))
    for i in range(len(s)):
        if s[i]%2==0:
            pa1+=1
        else:
            im1+=1
    m=int(stdin.readline().strip())
    s1=list(map(int,stdin.readline().strip().split()))
    s1=list(set(s1))
    for i in range(len(s1)):
        if s1[i]%2==0:
            pa2+=1
        else:
            im2+=1

    print(pa1*pa2+im1*im2)
