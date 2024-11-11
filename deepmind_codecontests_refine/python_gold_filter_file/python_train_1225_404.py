x,y = map(int,input().split())
n = sorted(list(map(int,input().split())))
print(sum(n[:y]))