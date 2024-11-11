H,W=map(int,input().split())
h,w=map(int,input().split())
S=H*W
print(S-h*W-w*H+h*w)