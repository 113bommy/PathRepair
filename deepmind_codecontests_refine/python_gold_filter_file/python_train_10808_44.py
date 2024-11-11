a,b,c,d=map(int,input().split())
print('NYoe s'[abs(a-c)<=d or (abs(a-b)<=d and abs(b-c)<=d)::2])