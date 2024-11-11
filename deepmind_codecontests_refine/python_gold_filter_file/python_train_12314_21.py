for i in range(int(input())):
    a=int(input())
    b=list(map(int,input().split()))
    print("NYOE S"[1 -(len(b)==len(set(b)))::2])