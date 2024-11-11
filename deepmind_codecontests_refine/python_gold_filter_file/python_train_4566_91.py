w, a,b=map(int, input().split())
print(max(b-a-w,a-b-w,0))