n=int(input())

if n%2==0:
    s=n//2*(n//2+1)-(n//2)**2
else:
    s=((n-1)//2*(n+1)//2)-((n+1)//2)**2

print(int(s))
