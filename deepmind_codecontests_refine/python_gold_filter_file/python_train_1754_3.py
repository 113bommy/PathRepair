n,a,b,c,d=map(int,input().split())
f=0
for i in range(n):f|=i*c-(~i+n)*d<=b-a<=i*d-(~i+n)*c
print('NYOE S'[f::2])