x,y=map(int,input().split())
s=sorted(list(map(int,input().split())))
print(sum(s[:y]))