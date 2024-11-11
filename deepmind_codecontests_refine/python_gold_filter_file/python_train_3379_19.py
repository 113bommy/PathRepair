a=int(input())
b=list(map(int,input().split()))[1:]
c=list(map(int,input().split()))[1:]
for i in range ( 1 , a+1 ):
    if (i not in b) and (i not in c):
        print("Oh, my keyboard!")
        exit()
print("I become the guy.")
