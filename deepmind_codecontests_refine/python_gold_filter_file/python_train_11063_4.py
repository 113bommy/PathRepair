for _ in range(int(input())):
    n=int(input())
    arr=list(map(int,input().split()))
    zero=0
    one=0
    for i in arr:
        if i==1:
            one+=1
        else:
            zero+=1
    if one<=n/2:
        print(zero)
        arr=["0"]*zero
        s=" ".join(arr)
        print(s)
    else:
        if one%2==0:
            print(one)
            arr=["1"]*one
            s=" ".join(arr)
            print(s)
        else:
            print(str(one-1))
            arr=["1"]*(one-1)
            s=" ".join(arr)
            print(s)