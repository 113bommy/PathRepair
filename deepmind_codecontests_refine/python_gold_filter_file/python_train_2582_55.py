a,b,c=map(int,input().split())
print('Yes' if (a>c and b<c) or (a<c and b>c) else 'No')