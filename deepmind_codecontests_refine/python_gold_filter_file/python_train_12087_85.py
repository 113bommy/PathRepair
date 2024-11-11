n=int(input())
a=list(map(int,input().split(" ")))
sum1=0
for i in range(len(a)):
    if(a[i]==0):
        sum1=sum1+1
if(sum1==len(a)):
    print("EASY")
else:
    print("HARD")