a,b,r=map(int,input().split())
column=(b//(2*r))
length=(a//(2*r))
count=column*length
if count==0:
    print("Second")
else:
    print("First")