p=lambda x:print(x,end=' ')
n=input();p(n+':')
n=int(n);s=n**.5
while n%2==0 and n>3:p(2);n//=2
d=3
while s>d and n>d:
 if n%d==0:p(d);n//=d
 else:d+=2
print(n)
