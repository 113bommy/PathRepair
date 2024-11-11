n = int(input())
dryer = [0]*101

al,ar = map(int,input().split())

for i in range(1,n):
    l,r = map(int,input().split())

    for j in range(l,r):
        dryer[j] = 1

x = 0
for i in range(al,ar):
    if dryer[i] == 0 :
        x += 1

print(x)