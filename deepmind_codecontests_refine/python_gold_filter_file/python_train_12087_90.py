n = int(input())
num = list(map(int,input().split()))
for i in num:
    if(i==1):
        s = "HARD"
        break;
    else:
        s = "EASY"
print(s)