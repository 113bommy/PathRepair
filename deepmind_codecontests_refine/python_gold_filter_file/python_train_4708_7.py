t= int(input())
 
for i in range(t):
    a = int(input())
    watch = input()
    isEven = False
    isOdd = False
    watch.split(' ')
    lists = []
    for val in watch.split(' '):
        lists.append(int(val))
    for i in lists:
        if(i % 2==0):
            isEven = True
        else:
            isOdd = True
    if(sum(lists) % 2 == 0):
        if(isEven and isOdd):
            print("YES")
        else:
            print("NO")
    else:
        print("YES")
    lists.clear()
        
