a,b,c=map(int,input().split())
e=a-b|b-c
print((e!=b&1)*len(f'{e&-e:b}')-1)