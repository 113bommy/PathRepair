H,W,A,B=map(int,input().split())

X="".join(map(str,[1]*A+[0]*(W-A)))+"\n"
Y="".join(map(str,[0]*A+[1]*(W-A)))+"\n"

print((X*B+Y*(H-B))[:-1])