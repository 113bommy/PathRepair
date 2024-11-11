b,a=map(int,input().split())
print(max(1,a-1 if (a-2) >= (b-(a+1)) else a+1))