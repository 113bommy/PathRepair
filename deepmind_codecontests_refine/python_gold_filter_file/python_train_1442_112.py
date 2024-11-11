_,a,b=map(int,input().split())
print('YNEOS'[(a*10+b)%4>0::2])
