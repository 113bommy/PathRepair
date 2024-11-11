x=int(input())
l=list(map(int,input().split()))
c=1
for i in l:
    if i==1:
       c=0
if c==0:
    print("HARD")
else:
    print("EASY")
