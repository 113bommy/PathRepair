x,a,b=map(int,input().split())
print("delicious" if a>=b else "safe" if x>= b-a else "dangerous")
