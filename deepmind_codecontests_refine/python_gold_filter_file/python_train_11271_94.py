for _ in range(int(input())):
    n=int(input())
    li=input()
    li1=li[n-1]

    for i in range(1,2*n-1,2):
        li1+=li[i]
    print(li1)