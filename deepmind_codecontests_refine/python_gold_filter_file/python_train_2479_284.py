H,W=map(int,input().split())
h,w=map(int,input().split())

print(max(H*W-h*W-w*(H-h),0))