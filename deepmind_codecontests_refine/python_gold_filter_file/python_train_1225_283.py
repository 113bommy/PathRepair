x,y = map(int,input().split())

t = list(map(int,input().split()))

t.sort()

print(sum(t[:y]))