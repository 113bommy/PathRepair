k,s=map(int,input().split())
print(len([1 for x in range(k+1) for y in range(k+1) if 0<=s-x-y<=k]))