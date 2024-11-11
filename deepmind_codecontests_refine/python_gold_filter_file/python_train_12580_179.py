a,b = map(int,input().split())
i = sorted(list(map(int,input().split())))

print(sum(i[-b:]))

