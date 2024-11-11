a,b,c=map(int,input().split())
print(c*2+(a*2+1 if a<b else (b*2+1 if a>b else b*2)))    
