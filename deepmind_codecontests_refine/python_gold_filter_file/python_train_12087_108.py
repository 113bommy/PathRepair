n=int(input())
num=list(map(int,input().split()))
for i in num:
    if(i==1):
        str = "HARD"
        break;
    else:
        str = "EASY"
print(str)