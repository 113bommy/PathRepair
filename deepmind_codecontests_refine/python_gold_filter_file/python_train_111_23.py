n = int(input())
li = list(map(int,input().split()))
a = max(li)
s =0
while True:
    for i in range(n):
        s += a-li[i]
    if s<=sum(li):
        a+=1
        s= 0
    else:
        print(a)
        break


