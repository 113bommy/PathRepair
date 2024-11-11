X,A,B = (int(T) for T in input().split())
print(['delicious','safe','dangerous'][(B-A>0)*(1+((X-(B-A))<0))])