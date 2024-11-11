for i in range(int(input())):
    n = int(input())
    arr=[int(x) for x in input().split()]
    if n==2 and sum(arr)==1:
        print(2)
    elif 1 in arr:
        print(arr.count(1)*2**(arr.count(0)))
    else:
        print(0)


