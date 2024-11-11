test = int(input())
while test > 0:
    n = int(input())
    check = (n//2) % 2
    sum=0
    if check == 0:
        print("YES")
        total=0
        total2=0
        list1=list(i*2 for i in range(1,(n//2)+1))
        list2=list(j*2+1 for j in range(0,(n//2)-1))
        for k in list1:
            total=total+k
        for a in list2:
            total2=total2+a
            list1.append(a)

        list1.append(total-total2)
        print(" ".join(str(x) for x in list1))

    else:
        print("NO")

    test = test-1
