I=lambda:map(int,input().split())
a=[x-y for x,y in zip(I(),I())]
p=sum(x//2 for x in a if x>0)
n=sum(x for x in a if x<0)
print('YNeos'[-n > p::2])