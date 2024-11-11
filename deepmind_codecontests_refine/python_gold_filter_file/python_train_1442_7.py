a,b,c=map(int,input().split())
print('YNEOS'[(a*100+b*10+c)%4!=0::2])