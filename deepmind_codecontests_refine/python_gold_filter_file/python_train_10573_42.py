a,d,b,c=map(int,input().split())
k=c if c<(a if a<b else b) else (a if a<b else b)
a-=k
k2=a if a<d else d
print(k*256 +k2*32)