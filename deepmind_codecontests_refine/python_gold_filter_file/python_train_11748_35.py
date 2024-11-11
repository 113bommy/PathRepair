x,a,b=map(int,input().split())
print("delicious" if -a+b<=0 else "safe" if 0<-a+b<=x else "dangerous")