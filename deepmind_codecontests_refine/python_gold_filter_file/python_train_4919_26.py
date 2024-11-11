n, s = list(map(int, input().split()))
 
if s//n>1:
    print("YES")
    printList = []
    for i in range(n-1):
        printList.append(2)
    printList.append(s-2*(n-1))
    print(*printList)
    print(1)
else:
    print("NO")