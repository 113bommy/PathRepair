a,b=map(int,input().split())
print(sum(sorted(map(int,input().split()))[a-b:]))