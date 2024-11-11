n,k = map(int,input().split())
x = input()
print(x[:k-1]+x[k-1].lower()+x[k:])