x,a,b=map(int,input().split())
print(['B','A'][abs(x-b)>abs(x-a)])