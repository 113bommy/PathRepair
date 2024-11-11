a,b,c = map(int,input().split())
print("Yes" if (a<c and c<b) or (a>c and c>b) else "No")