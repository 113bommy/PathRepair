n=int(input())
if n%2==1:
    ans=0
else:
    c=n/2
    if c%2==1:
        ans=int(n/4)
    else:
        ans=int(n/4-1)

print(ans)
