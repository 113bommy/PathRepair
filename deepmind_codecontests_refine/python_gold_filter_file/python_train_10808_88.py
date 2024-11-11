a,b,c,x=map(int,input().split())
print('Yes' if abs(c-a)<=x or abs(b-a)<=x and abs(c-b)<=x else 'No')