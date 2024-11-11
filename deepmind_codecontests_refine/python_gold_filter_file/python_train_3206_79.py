a,b,k = map(int,input().split())
print(" ".join(map(str,[max(0,a-k),max(0,b-max(0,k-a))])))
