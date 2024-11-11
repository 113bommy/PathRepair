k=list(map(int,input().split()))
k.sort()
print(max(0,k[2]-k[1]-k[0]+1))