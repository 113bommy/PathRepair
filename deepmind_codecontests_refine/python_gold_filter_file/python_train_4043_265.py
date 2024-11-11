a,b,c=map(int,input().split())
print(["YES","NO"][c-a<0 or c-a>b])