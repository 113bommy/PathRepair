n = int(input())
l1 = list(map(int,input().split()))
l2 = list(map(int,input().split()))
t1 = l1[1:]
t2 = l2[1:]
cnt = 0
while cnt<10000:
    TopT1 = t1.pop(0)
    TopT2 = t2.pop(0)
    if (TopT1 < TopT2):
        t2.append(TopT1)
        t2.append(TopT2)
    else:
        t1.append(TopT2)
        t1.append(TopT1)
    cnt+=1
    if (len(t1)<=0):
        print(cnt,'2')
        exit(0)
    elif(len(t2)<=0):
        print(cnt,'1')
        exit(0)
    if (t1 == l1[1:] and t2 == l2[1:]):
        print(-1)
        exit(0)
print(-1)
    
    

