a,b,k = map(int,input().split())
print(max(0,a-k),min(b,max(0,a+b-k)))