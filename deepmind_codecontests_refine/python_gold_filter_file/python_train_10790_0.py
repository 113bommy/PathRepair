a,b,c = map(int,input().split())
print([(a+b+c)//2*2,(min(a,b)+c)*2][min(a,b)+c <= max(a,b)])