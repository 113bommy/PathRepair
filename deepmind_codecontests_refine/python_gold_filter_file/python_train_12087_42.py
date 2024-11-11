n = int(input())
lis = [int(i) for i in input().split()]
count = 0
for i in range(n):
    if(lis[i] == 1):
        count = count + 1
if(count >= 1):
    print("HARD");
else:
    print("EASY");