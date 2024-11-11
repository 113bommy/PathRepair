w,a,b=map(int,input().split())
print(b-(a+w) if b>a+w else a-(b+w) if b+w<a else 0)