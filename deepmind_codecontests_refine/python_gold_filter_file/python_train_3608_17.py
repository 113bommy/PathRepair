n = int(input())
a = list(map(int,input().split()))
total = sum(a)+1
total = int(total/2)
i = 0
sm = 0
while sm<total:
    sm+=a[i]
    i+=1
print(i)
    