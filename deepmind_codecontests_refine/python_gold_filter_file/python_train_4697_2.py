n = list(map(int,input().split()))
n.sort()
print(max(0,n[2]-n[1]-n[0]+1))