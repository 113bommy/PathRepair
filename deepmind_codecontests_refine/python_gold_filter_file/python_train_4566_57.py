w,a,b = map(int, input().split())
print(max(b-a-w,0,a-b-w))