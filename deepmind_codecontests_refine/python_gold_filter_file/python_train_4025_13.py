R=lambda:map(int,input().split())
h,m=R()
H,D,C,N=R()
H+=N-1
print(min(H//N*C,(H+max(0,(20-h)*60-m)*D)//N*C*.8))