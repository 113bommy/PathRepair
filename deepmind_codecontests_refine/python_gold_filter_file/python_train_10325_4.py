input()
a=*map(int,input().split()),
s=sum(a)
print('YNEOS'[s%2or 2*max(a)>s::2])