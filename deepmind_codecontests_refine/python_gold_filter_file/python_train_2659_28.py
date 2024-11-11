friendCount,height = list(map(int,input().split()))
print(sum((1 if x<=height else 2) for x in map(int,input().split())))