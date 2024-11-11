x,y=map(int,input().split())
l1=list(map(str,input().split()))
l2=list(map(str,input().split()))
for _ in range(int(input())):
    k=int(input())
    print(l1[k%x-1],end="")
    print(l2[k%y-1])