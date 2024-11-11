n,a,b=map(int,input().split())
print(max(b*(n-1)+a-(b+a*(n-1))+1,0))