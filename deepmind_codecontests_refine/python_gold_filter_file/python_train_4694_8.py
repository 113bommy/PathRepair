n=int(input())
x,y=[list(map(int,input().split()))for _ in range(2)]
d=[abs(s-t)for s,t in zip(x,y)]
f=lambda n:sum([s**n for s in d])**(1/n)
print(f(1),f(2),f(3),max(d),sep='\n')
