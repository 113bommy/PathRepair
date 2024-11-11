k,n,w=map(int,input().split())
print(max((w+1)*w*k//2-n,0))