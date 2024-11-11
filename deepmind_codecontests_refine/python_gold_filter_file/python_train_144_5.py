x,y = map(int, input().split())
li =list(map(int, input().split()))

print(max(0, max([li[i]-li[i+1]-y for i in range(x-1)])))
