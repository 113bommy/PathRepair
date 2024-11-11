w,a,b = map(int,input().split())
ma = max(a,b)
mi = min(a,b)
print(max(ma-(mi+w),0))
