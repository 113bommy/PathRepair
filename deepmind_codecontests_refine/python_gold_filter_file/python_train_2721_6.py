from math import ceil

n = int(input())

l = list(map(int,input().split()))
count1 = 0
count2 = 0
for i in l:
    if i>0:
        count1+=1
    elif i<0:
        count2+=1


if count1>=ceil(n/2):
    print(1)
elif count2>=ceil(n/2):
    print(-1)

else:
    print(0)