for _ in range(int(input())):
    n=int(input())
    s=input()
    k=''
    for i in s:
        if int(i)%2:
            k+=i
            if len(k)==2:
                print(k)
                break
    else:
        print(-1)