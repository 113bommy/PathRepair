H,W=map(int,input().split())
hi,wi=map(int,input().split())

print(W*H-W*hi-H*wi+hi*wi)