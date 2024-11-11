a,b,c,d = map(int,input().split())
print('Yes'if abs(a-c)<=d or (abs(c-b)<=d and abs(b-a)<=d) else 'No')