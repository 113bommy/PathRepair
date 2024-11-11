a,b,c = [int(s) for s in input().split(" ")]
ret = min(a+b+1,c) + b
print(ret)