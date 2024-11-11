x,a,b = map(int,input().split())
print("dangerous" if b-a>x else "safe" if b-a>0 else "delicious")