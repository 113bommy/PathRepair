n,a,b=map(int,input().split())
max=0
if a>b:
    temp=a
    a=b
    b=temp

for i in range(1,a+1):
    tempn=n
    c=a//i
    if c>=n:
        continue
    tempn-=c
    d=b//tempn
    if(d>=i):
        if i>max:
            max=i
    else:
        if d>max:
            max=d

print(max)