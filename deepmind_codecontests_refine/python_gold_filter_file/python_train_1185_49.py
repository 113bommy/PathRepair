a,b,c,d=map(int,input().split())
s=a/b
t=c/d
print(s/(1-(1-s)*(1-t)))