H,W = map(int, input().split())
h,w = map(int, input().split())

print(max((H-h)*(W-w),0))