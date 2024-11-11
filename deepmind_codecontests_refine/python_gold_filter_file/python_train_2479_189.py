H,W = map(int,input().split())
h,w = map(int,input().split())

print(H*W-(w*H+h*W-h*w))