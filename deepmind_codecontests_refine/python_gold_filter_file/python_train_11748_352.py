x,a,b = map(int, input().split())
print("delicious" if a>=b else "safe" if a+x>=b else "dangerous")