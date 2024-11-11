X,A,B = map(int,input().split())
print("dangerous" if B-A > X else "safe" if B>A else "delicious")