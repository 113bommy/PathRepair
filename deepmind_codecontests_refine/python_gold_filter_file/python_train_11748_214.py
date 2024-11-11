x,a,b = map(int,input().split())
print(['delicious','safe','dangerous'][(b>a)+(b>a+x)])