a,b,c,d=map(int,input().split())
print('NYoe s'[abs(a-c)<=d or (abs(b-a)<=d and abs(c-b)<=d)::2])