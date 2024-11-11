n,m=map(int,input().split())
a=[int(input(),2)for _ in range(n)]
 
s=t=0
for x in a:
    t|=s&x
    s|=x
print(('YES','NO')[all(x&s&~t for x in a)])