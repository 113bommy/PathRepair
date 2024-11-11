a,b,c,d=list(map(int,input().split()))
nu=a*d
de=b*c+a*d-a*c
ans=nu/de
print(float(ans))