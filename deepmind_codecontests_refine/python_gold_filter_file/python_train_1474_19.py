input()
a=sorted(map(int,input().split()))
if any(x==y for x,y in zip(a,a[2:])):print('NO');exit()
b=a[::2]
c=a[1::2]
print('YES',len(b),*b,len(c),*c[::-1])