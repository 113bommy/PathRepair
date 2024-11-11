k,a,b=map(int,input().split())
print(b//k-a//k-bool(a%k)+1)