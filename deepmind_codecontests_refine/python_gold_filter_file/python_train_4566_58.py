w,a,b=map(int,input().split())
print(b-(a+w) if a+w<b else a-(b+w) if b+w<a else 0)