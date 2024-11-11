n,m = map(int,input().split())
l = list(map(int,input().split()))

for i in range(n,100000):
    k = i
    c=0
    while k>0:
        if k%10 not in l:
            c+=1
        else:
            break
        k = k//10
    if len(str(i))==c:
        print(i)
        break