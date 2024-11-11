l1 = [int(x) for x in input().split()]
l2 = [int(x) for x in input().split()]
n,k = l1[0],l1[1]

if k>n:
    print(-1)
else:
    l2.sort(reverse=True)
    #print(l2)
    print(l2[k-1],l2[k-1])