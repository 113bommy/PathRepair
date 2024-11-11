n=int(input())
f=list(map(int,input().split()))
f.sort(reverse=True);sm=0;p=0
for i in range(n):sm+=f[i]
for i in range(n):
    p+=f[i];sm-=f[i]
    if p>sm:
        print(i+1)
        break