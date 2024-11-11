n = int(input())
length = n
group1 = []
group2 = []
if length%4 ==0:
    for i in range(1,int(length/2)):
        if i%2 ==1:
            group1.append(i)
            group1.append(n-i+1)
        else:
            group2.append(i)
            group2.append(n-i+1)
    print (0)
    print (len(group1),*group1)
else:
    if length%2 == 0:
        k = 0
        for i in range(1,int(length/2)):
            # k = 0
            if i%2 ==1:
                group1.append(i)
                group1.append(n-k)
            else:
                group2.append(i)
                group2.append(n-k)
            k += 1
        group1.append(int(length/2))
        group2.append(int(length%2+1))
        print (1)
        print (len(group1),*group1)
    else:
        #1 2 3 4 5 6 7
        if length%4 == 3:
            k = 0
            for i in range(4,int(length/2+3)):
                if i%2 ==1:
                    group1.append(i)
                    group1.append(n-k)
                else:
                    group2.append(i)
                    group2.append(n-k)
                k+=1
            group1.append(1)
            group1.append(2)
            group2.append(3)
            print (0)
            print(len(group1),*group1)
        if length%4 == 1:
            k = 0
            for i in range(2,int(length/2+3)):
                if i%2 ==1:
                    group1.append(i)
                    group1.append(n-k)
                else:
                    group2.append(i)
                    group2.append(n-k)
                k+=1
            group1.append(1)
            print (1)
            print (len(group1),*group1)