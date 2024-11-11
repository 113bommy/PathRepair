r=range;k,s=map(int,input().split())
print(len([0 for x in r(k+1) for y in r(k+1) if 0<=s-x-y<=k]))