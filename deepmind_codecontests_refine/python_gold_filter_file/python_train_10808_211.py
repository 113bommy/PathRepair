a,b,c,d=map(int,input().split())
print('YNeos'[abs(a-c)>d and (abs(a-b)>d or abs(c-b)>d)::2])