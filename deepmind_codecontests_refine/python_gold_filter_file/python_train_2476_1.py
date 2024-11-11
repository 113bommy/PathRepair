a,b,c,d=map(int,input().split())
print("No"if c//b+int(c%b>0)>a//d+int(a%d>0) else"Yes")