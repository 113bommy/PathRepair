a=input().split()

s=int(a[0])
d=int(a[1])

if s<0:
    s=s*(-1)
if d<0:
    d=d*(-1)

p=s+d
step=int(a[2])



if p>step:
    print("No")
elif p==step:
    print("Yes")
else:
    n=p-step
    if n%2==0:
        print("Yes")
    else:
        print("No")
